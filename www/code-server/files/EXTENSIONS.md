# Extension Cookbook for code-server on FreeBSD

Master copy: https://github.com/joneum/FreeBSD-CodeServer (the file in
`share/doc/code-server/` is a snapshot shipped with the package).

Since code-server 4.135.0_1 the FreeBSD port installs extensions from the
Open VSX registry as on any other platform. Some popular extensions bundle
or download **native Linux binaries** (language servers, debug adapters)
that do not run on FreeBSD. In most cases the fix is the same two-step
recipe:

1. install the native tool from packages/ports, and
2. point the extension at it via a setting.

All entries below were verified on FreeBSD 15.1 with code-server 4.135.0_1
as of September 2026: the extension installs, the setting keys are taken
from the extensions' own manifests, and the binary paths from the ports'
packing lists.

## Recipes

| Language | Extension | Install | Setting (settings.json) |
|---|---|---|---|
| Rust | `rust-lang.rust-analyzer` | `pkg install rust-analyzer` | `"rust-analyzer.server.path": "/usr/local/bin/rust-analyzer"` |
| Go | `golang.go` | `pkg install go gopls delve` | `"go.alternateTools": { "gopls": "/usr/local/bin/gopls", "dlv": "/usr/local/bin/dlv" }` |
| C/C++ | `llvm-vs-code-extensions.vscode-clangd` | `pkg install llvm21` | `"clangd.path": "/usr/local/llvm21/bin/clangd"` |
| C/C++ debug | `llvm-vs-code-extensions.lldb-dap` | `pkg install llvm21` | `"lldb-dap.executable-path": "/usr/local/llvm21/bin/lldb-dap"` |
| Python | `ms-python.python` | `pkg install python` | `"python.defaultInterpreterPath": "/usr/local/bin/python3"` (the extension needs a findable interpreter; for type checking add `ms-pyright.pyright`, pure JS, no setup) |
| Java | `redhat.java` | `pkg install openjdk21` | `"java.jdt.ls.java.home": "/usr/local/openjdk21"` |
| Lua | `sumneko.lua` | `pkg install lua-language-server` | `"Lua.misc.executablePath": "/usr/local/bin/lua-language-server"` |
| Shell (lint) | `timonwong.shellcheck` | `pkg install hs-ShellCheck` | `"shellcheck.executablePath": "/usr/local/bin/shellcheck"` |
| Shell (format) | `foxundermoon.shell-format` | `pkg install shfmt` | `"shellformat.path": "/usr/local/bin/shfmt"` |
| Python (lint) | `charliermarsh.ruff` | `pkg install ruff` | `"ruff.path": ["/usr/local/bin/ruff"]` |
| Terraform | `hashicorp.terraform` | `pkg install terraform terraform-ls` | `"terraform.languageServer.path": "/usr/local/bin/terraform-ls"` |
| Zig | `ziglang.vscode-zig` | `pkg install zig zls` | `"zig.path": "/usr/local/bin/zig", "zig.zls.path": "/usr/local/bin/zls"` |
| Ruby | `shopify.ruby-lsp` | `pkg install ruby rubygem-ruby-lsp` | `"rubyLsp.rubyExecutablePath": "/usr/local/bin/ruby"` |

Note: versioned package names and paths (`llvm21`, `openjdk21`, the
`py312-` prefix) follow the current ports defaults; when the default
changes, check the new path with `pkg info -l <package>`.

Put the settings into the User settings of code-server (Settings UI, or
`~/.local/share/code-server/User/settings.json`; with a custom
`--user-data-dir` the file lives below that directory). After changing a
path, run "Developer: Reload Window"; newly installed extensions appear
after a browser reload.

Copy-paste block with everything combined:

```json
{
  "rust-analyzer.server.path": "/usr/local/bin/rust-analyzer",
  "go.alternateTools": {
    "gopls": "/usr/local/bin/gopls",
    "dlv": "/usr/local/bin/dlv"
  },
  "clangd.path": "/usr/local/llvm21/bin/clangd",
  "lldb-dap.executable-path": "/usr/local/llvm21/bin/lldb-dap",
  "python.defaultInterpreterPath": "/usr/local/bin/python3",
  "java.jdt.ls.java.home": "/usr/local/openjdk21",
  "Lua.misc.executablePath": "/usr/local/bin/lua-language-server",
  "shellcheck.executablePath": "/usr/local/bin/shellcheck",
  "shellformat.path": "/usr/local/bin/shfmt",
  "ruff.path": ["/usr/local/bin/ruff"],
  "terraform.languageServer.path": "/usr/local/bin/terraform-ls",
  "zig.path": "/usr/local/bin/zig",
  "zig.zls.path": "/usr/local/bin/zls",
  "rubyLsp.rubyExecutablePath": "/usr/local/bin/ruby"
}
```

Tip: if you install packages from your own poudriere repository, add the
language server packages to your build list.

## Known limitations

| Extension | Status | Alternative |
|---|---|---|
| Pylance (`ms-python.vscode-pylance`) | licensed for Microsoft builds only, not on Open VSX | `ms-pyright.pyright` |
| C/C++ (`ms-vscode.cpptools`) | licensed for Microsoft builds only | `vscode-clangd` + `lldb-dap` (see above) |
| Live Share | licensed for Microsoft builds only | none |
| Python debugging (`ms-python.debugpy`) | installs, but bundles Linux-only native wheels; launch (F5) may fail | `pkg install py312-debugpy`, start your program with `python3 -m debugpy --listen 5678 --wait-for-client prog.py` and use a "Remote Attach" launch configuration (attaches via port, not via the process picker) |
| JavaScript/Node "Attach to Process" picker | the bundled js-debug uses its own ps(1) invocation that misparses on FreeBSD | attach via port (`--inspect`) instead of the picker |
| Jupyter (`ms-toolsai.jupyter`) | native zeromq addon, does not load on FreeBSD | run JupyterLab natively and use the browser |
| PHP (devsense) | closed-source Linux language server binaries | `bmewburn.vscode-intelephense-client` |

Found a working recipe that is missing here, or one that no longer works?
Please open an issue or pull request at
https://github.com/joneum/FreeBSD-CodeServer.
