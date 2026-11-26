// Print a zsh completion function for the paseo CLI, generated from its
// commander definition.  Usage: node gen-zsh-completion.mjs <cli dist dir>
import path from "node:path";
import { pathToFileURL } from "node:url";

const dist = path.resolve(process.argv[2]);
const { createCli } = await import(pathToFileURL(path.join(dist, "cli.js")).href);
const program = createCli();

const oneLine = (s) => (s || "").replace(/\s+/g, " ").trim();
const q = (s) => oneLine(s).replace(/\\/g, "\\\\").replace(/'/g, "'\\''").replace(/:/g, "\\:")
  .replace(/\[/g, "\\[").replace(/\]/g, "\\]");
const qd = (s) => oneLine(s).replace(/'/g, "'\\''").replace(/:/g, "\\:");
const fn = (names) => "_paseo" + names.map((n) => "_" + n.replace(/[^A-Za-z0-9]/g, "_")).join("");

// Completion action for an argument, from its name or its choices.
function action(name, choices) {
  if (choices) return `(${choices.map(q).join(" ")})`;
  if (/(^|[-_])(dir|directory|cwd|folder)$/i.test(name)) return "_files -/";
  if (/(^|[-_])(path|file|filename)$/i.test(name)) return "_files";
  return " ";
}

function optionSpecs(cmd) {
  const specs = [];
  let ownHelp = false;
  for (const o of cmd.options) {
    if (o.hidden) continue;
    if (o.short === "-h" || o.long === "--help") ownHelp = true;
    const takesArg = o.required || o.optional;
    const repeatable = o.variadic || Array.isArray(o.defaultValue);
    // "--name=" takes the argument either after "=" or as the next word.
    const flags = [o.short, o.long && takesArg ? `${o.long}=` : o.long].filter(Boolean);
    const desc = q(o.description);
    const argName = (o.flags.match(/[<[]([^>\]]+?)(\.\.\.)?[>\]]/) || [, "value"])[1];
    // --cwd <path> and --dir <path> name a directory.
    const actName = /^--(cwd|dir|directory|folder)$/.test(o.long) ? "dir" : argName;
    const arg = takesArg
      ? `${o.optional ? "::" : ":"}${q(argName)}:${action(actName, o.argChoices)}`
      : "";
    const plain = [o.short, o.long].filter(Boolean);
    const excl = repeatable ? "*" : plain.length > 1 ? `(${plain.join(" ")})` : "";
    const names = flags.length > 1 ? `{${flags.join(",")}}` : flags[0];
    specs.push(flags.length > 1
      ? `'${excl}'${names}'[${desc}]${arg}'`
      : `'${excl}${names}[${desc}]${arg}'`);
  }
  if (!ownHelp) specs.push("'(- *)'{-h,--help}'[display help for command]'");
  return specs;
}

const out = ["#compdef paseo", "", "# Generated from the paseo CLI's commander definition.", ""];
const seen = new Map();
function emit(cmd, names) {
  const where = ["paseo", ...names].join(" ");
  const name = fn(names);
  if (seen.has(name)) throw new Error(`${where} and ${seen.get(name)} both map to ${name}`);
  seen.set(name, where);
  const subs = cmd.commands.filter((c) => !c._hidden && c.name() !== "help");
  const lines = [`${name}() {`];
  if (subs.length) {
    if (cmd.registeredArguments.length)
      throw new Error(`${where} has both subcommands and arguments, which this generator does not handle`);
    lines.push("  local curcontext=\"$curcontext\" state line ret=1", "  typeset -A opt_args");
    lines.push("  _arguments -C \\");
    for (const s of optionSpecs(cmd)) lines.push(`    ${s} \\`);
    lines.push("    '1: :->cmds' \\", "    '*:: :->args' && ret=0", "  case $state in", "    cmds)");
    lines.push("      local -a cmds", "      cmds=(");
    for (const c of subs) {
      for (const n of [c.name(), ...c.aliases()]) lines.push(`        '${n}:${qd(c.description())}'`);
    }
    lines.push("      )", "      _describe -t commands 'paseo command' cmds && ret=0", "      ;;", "    args)", "      case $line[1] in");
    for (const c of subs) {
      lines.push(`        ${[c.name(), ...c.aliases()].join("|")}) ${fn([...names, c.name()])} && ret=0 ;;`);
    }
    lines.push("      esac", "      ;;", "  esac", "  return ret", "}", "");
  } else {
    lines.push("  _arguments \\");
    for (const s of optionSpecs(cmd)) lines.push(`    ${s} \\`);
    for (const [i, a] of cmd.registeredArguments.entries()) {
      // "*::" would change $words rather than mark the argument optional.
      const pos = a.variadic ? "*:" : `${i + 1}${a.required ? ":" : "::"}`;
      lines.push(`    '${pos}${q(a.name())}:${action(a.name(), a.argChoices)}' \\`);
    }
    lines[lines.length - 1] = lines[lines.length - 1].replace(/ \\$/, "");
    lines.push("}", "");
  }
  out.push(...lines);
  for (const c of subs) emit(c, [...names, c.name()]);
}
emit(program, []);
// Fail the build rather than ship a near-empty completion if the CLI ever
// registers its commands lazily.
if (!program.commands.some((c) => c.name() === "daemon") || seen.size < 20)
  throw new Error(`only ${seen.size} commands found; has createCli() changed?`);
out.push('_paseo "$@"', "");
process.stdout.write(out.join("\n"));
