# Tiny helper binaries for thc TclHttp-daemon providing the
# functionality not available in the TCL itself:
package ifneeded crypt 1.0 [list load [file join $dir libcrypt.so]]
package ifneeded setuid 1.0 [list load [file join $dir libsetuid.so]]
package ifneeded limit 1.0 [list load [file join $dir liblimit.so]]
