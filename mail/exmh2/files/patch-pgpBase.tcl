Index: lib/pgpBase.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/pgpBase.tcl,v
retrieving revision 1.7
retrieving revision 1.8
diff -r1.7 -r1.8
8a9,12
> # Revision 1.8  2003/05/20 03:43:30  welch
> # pgpPgp65.tcl added version check improvement for PGP 6.5 (Neil Rickert)
> #   (added . - and _ to the pattern, too (kre))
> #
205c209
< set pgp(pgp6,pat_Version) "Version:\[ \t\]*6\.5.*"
---
> set pgp(pgp6,pat_Version) "Version:\[ \t-._A-Za-z\]*6\.5.*"
