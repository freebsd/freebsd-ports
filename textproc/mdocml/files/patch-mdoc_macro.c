Log Message:
-----------
If a stray .It follows .El, we are no longer in the list,
even though the list is still the last processed macro.
This fixes a regression introduced in mdoc_macro.c rev. 1.138:
Ulrich Spoerlein <uqs at FreeBSD> reports that various of their
kernel manuals trigger assertions.

Modified Files:
--------------
    mdocml:
        mdoc_macro.c

Revision Data
-------------
Index: mdoc_macro.c
===================================================================
RCS file: /usr/vhosts/mdocml.bsd.lv/cvs/mdocml/mdoc_macro.c,v
retrieving revision 1.140
retrieving revision 1.141
diff -Lmdoc_macro.c -Lmdoc_macro.c -u -p -r1.140 -r1.141
--- mdoc_macro.c
+++ mdoc_macro.c
@@ -1041,7 +1041,8 @@ blk_full(MACRO_PROT_ARGS)
 
 	if (tok == MDOC_It) {
 		for (n = mdoc->last; n; n = n->parent)
-			if (n->tok == MDOC_Bl)
+			if (n->tok == MDOC_Bl &&
+			    ! (n->flags & MDOC_VALID))
 				break;
 		if (n == NULL) {
 			mandoc_vmsg(MANDOCERR_IT_STRAY, mdoc->parse,
