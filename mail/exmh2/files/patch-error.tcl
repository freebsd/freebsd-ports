Index: lib/error.tcl
===================================================================
RCS file: /cvsroot/exmh/exmh/lib/error.tcl,v
retrieving revision 1.2
retrieving revision 1.3
diff -c -r1.2 -r1.3
*** error.tcl	1999/03/26 18:02:56	1.2
--- error.tcl	2001/01/03 23:51:59	1.3
***************
*** 118,123 ****
--- 118,126 ----
  
  proc ExmhMailError { w errInfo } {
      global exmh
+     if [file exists [Env_Tmp]/exmhErrorMsg] {
+         file delete [Env_Tmp]/exmhErrorMsg
+     }
      if [catch {open [Env_Tmp]/exmhErrorMsg w} out] {
  	Exmh_Status "Cannot open [Env_Tmp]/exmhErrorMsg" purple
  	return
