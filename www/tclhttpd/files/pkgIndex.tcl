# Tiny helper binaries for thc TclHttp-daemon providing the
# functionality not available in the TCL itself:
package ifneeded crypt 1.0 [list load $dir/@LIB@]
package ifneeded setuid 1.0 [list load $dir/@LIB@]
package ifneeded limit 1.0 [list load $dir/@LIB@]
