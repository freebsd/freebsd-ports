Index: lib/pgpPgp5.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/pgpPgp5.tcl,v
retrieving revision 1.6
retrieving revision 1.7
diff -c -r1.6 -r1.7
*** pgpPgp5.tcl	2000/04/18 18:38:33	1.6
--- pgpPgp5.tcl	2001/01/04 02:24:46	1.7
***************
*** 1,6 ****
--- 1,17 ----
  # pgpPgp5.tcl
  
  # $Log: pgpPgp5.tcl,v $
+ # Revision 1.7  2001/01/04 02:24:46  bmah
+ # Add +force to PGP5 flags.  This fixes
+ # a bug where PGP5 couldn't verify clearsigned messages under some
+ # circumstances.  In my testing I was only able to make this happen
+ # with clearsigned messages and multipart/mime, which produces some
+ # rather strange output anyways.  But this doesn't seem to hurt
+ # anything.
+ #
+ # Submitted-by:	Dave Tweten <tweten@nas.nasa.gov>, via the FreeBSD
+ # 		Project
+ #
  # Revision 1.6  2000/04/18 18:38:33  valdis
  # Fix quote character to use ascii rather than iso8859-ish one
  #
***************
*** 88,94 ****
  #############
  # Exec_Batch
  # Batchmode flags
! set pgp(pgp5,flags_batch) {+armorlines=0 +batchmode=on +verbose=0}
  #
  proc Pgp_pgp5_PassFdSet {} {
      global env
--- 99,105 ----
  #############
  # Exec_Batch
  # Batchmode flags
! set pgp(pgp5,flags_batch) {+armorlines=0 +batchmode=on +force +verbose=0}
  #
  proc Pgp_pgp5_PassFdSet {} {
      global env
