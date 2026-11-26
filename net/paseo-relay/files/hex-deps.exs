# Unpack Hex package tarballs into deps/ as "mix deps.get" would, but
# without the Hex registry or network access: every value that mix and Hex
# later check (.hex, hex_metadata.config) comes from mix.lock and the
# tarballs.
#
# Usage: elixir hex-deps.exs <tarball directory> <package> ...
# Run it in the project directory, next to mix.lock.

[distdir | packages] = System.argv()

# Read mix.lock the way Mix.Dep.Lock does.
opts = [file: "mix.lock", emit_warnings: false]
{:ok, quoted} = Code.string_to_quoted(File.read!("mix.lock"), opts)
{lock, _binding} = Code.eval_quoted(quoted, [], opts)

for package <- packages do
  name = String.to_atom(package)

  {pkg, version, inner, managers, repo, outer} =
    case Map.get(lock, name) do
      {:hex, pkg, version, inner, managers, _deps, repo, outer} ->
        {pkg, version, inner, managers, repo, outer}

      nil ->
        raise "#{package} is not in mix.lock"

      entry ->
        raise "#{package} is not a Hex package in mix.lock: #{inspect(entry)}"
    end

  tarball = Path.join(distdir, "#{pkg}-#{version}.tar")
  data = File.read!(tarball)

  if Base.encode16(:crypto.hash(:sha256, data), case: :lower) != outer do
    raise "#{tarball} does not match the outer checksum in mix.lock"
  end

  {:ok, files} = :erl_tar.extract({:binary, data}, [:memory])
  files = Map.new(files, fn {path, contents} -> {List.to_string(path), contents} end)

  dest = Path.join("deps", package)
  File.rm_rf!(dest)
  File.mkdir_p!(dest)

  :ok =
    :erl_tar.extract({:binary, files["contents.tar.gz"]},
      [:compressed, cwd: String.to_charlist(dest)])

  File.write!(Path.join(dest, "hex_metadata.config"), files["metadata.config"])

  meta = %{
    name: Atom.to_string(pkg),
    version: version,
    repo: repo,
    managers: managers,
    inner_checksum: inner,
    outer_checksum: outer
  }

  # The manifest that Hex.SCM writes (encode_manifest/6 in lib/hex/scm.ex)
  # and checks against mix.lock.
  File.write!(Path.join(dest, ".hex"), :erlang.term_to_binary({{:hex, 2, 0}, meta}))
  IO.puts("===>  Unpacked Hex package #{pkg} #{version}")
end
