Index: lib/pgpPgp65.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/pgpPgp65.tcl,v
retrieving revision 1.5
retrieving revision 1.6
diff -r1.5 -r1.6
3a4,8
> # Revision 1.6  2003/05/20 03:22:57  welch
> # pgpPgp65.tcl - Added +compatible=off to batchmode flags (Neil Rickert)
> # preferences.tcl - In the toplevel display,
> #     changed row of unsorted buttons to a sorted listbox
> #
71c76,77
< set pgp(pgp6,flags_batch) {+armorlines=0 "+comment=$pgp(pgp6,comment)" +batchmode=on +verbose=0 +pager=cat}
---
> # +compatible=off contributed by Neil Rickert
> set pgp(pgp6,flags_batch) {+armorlines=0 "+comment=$pgp(pgp6,comment)" +batchmode=on +compatible=off +verbose=0 +pager=cat}
