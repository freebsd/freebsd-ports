# Print "name path" for every patch listed in cef/patch/patch.cfg, the list
# the CEF patcher (cef/tools/patcher.py) works from.  Entries with a
# "condition" are only applied when that environment variable is set, which
# the port never does.
BEGIN { FS = "'" }
/^[[:space:]]*\{/ { name = ""; path = "."; cond = 0 }
$2 == "name" && $3 ~ /^[[:space:]]*:[[:space:]]*$/ { name = $4 }
$2 == "path" && $3 ~ /^[[:space:]]*:[[:space:]]*$/ { path = $4 }
$2 == "condition" { cond = 1 }
/^[[:space:]]*\}/ { if (name != "" && !cond) print name, path; name = "" }
