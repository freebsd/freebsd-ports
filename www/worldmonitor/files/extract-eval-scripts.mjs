// Prints the Lua scripts of a seeder as a JSON array, so that the Redis
// REST proxy can add them to its list of allowed EVAL scripts.
import { readFileSync } from 'node:fs';

const source = readFileSync(process.argv[2], 'utf8');
const scripts = [];
for (const m of source.matchAll(/const [A-Z_]+_SCRIPT = `([^`]*)`\.trim\(\);/g)) {
  scripts.push(m[1].trim());
}
if (scripts.length === 0) {
  console.error('no scripts found in ' + process.argv[2]);
  process.exit(1);
}
console.log(JSON.stringify(scripts));
