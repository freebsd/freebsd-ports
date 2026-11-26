// Print, one per line and relative to the current directory, the package
// directories that make up the run-time closure of the packages named on the
// command line, resolved the way Node.js does from the directory given first.
// Packages listed after "--exclude" (and everything below them) are skipped:
// misc/paseo provides those.  Fails if a dependency declared in the
// package.json of that first directory is in neither list, so a new upstream
// dependency cannot go missing silently.
import { existsSync, readFileSync, realpathSync } from "node:fs";
import path from "node:path";

const args = process.argv.slice(2);
const split = args.indexOf("--exclude");
const startDir = path.resolve(args[0]);
const roots = split === -1 ? args.slice(1) : args.slice(1, split);
const excluded = new Set(split === -1 ? [] : args.slice(split + 1));
const seen = new Set();

function packageDir(name, from) {
  for (let dir = from; ; dir = path.dirname(dir)) {
    const manifest = path.join(dir, "node_modules", name, "package.json");
    if (existsSync(manifest)) return path.dirname(realpathSync(manifest));
    if (path.dirname(dir) === dir) return null;
  }
}

function walk(name, from) {
  if (excluded.has(name)) return;
  const dir = packageDir(name, from);
  if (dir === null) throw new Error(`cannot resolve ${name} from ${from}`);
  if (seen.has(dir)) return;
  seen.add(dir);
  const manifest = JSON.parse(readFileSync(path.join(dir, "package.json"), "utf8"));
  for (const dep of Object.keys(manifest.dependencies ?? {})) walk(dep, dir);
  for (const dep of Object.keys(manifest.optionalDependencies ?? {})) {
    if (packageDir(dep, dir) !== null) walk(dep, dir);
  }
}

const declared = JSON.parse(readFileSync(path.join(startDir, "package.json"), "utf8"));
for (const dep of Object.keys(declared.dependencies ?? {})) {
  if (!roots.includes(dep) && !excluded.has(dep)) {
    throw new Error(`${dep} is neither installed nor taken from misc/paseo`);
  }
}

for (const name of roots) walk(name, startDir);
for (const dir of [...seen].sort()) console.log(path.relative(process.cwd(), dir));
