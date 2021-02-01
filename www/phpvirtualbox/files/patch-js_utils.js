--- js/utils.js.orig	2018-11-09 09:43:10 UTC
+++ js/utils.js
@@ -1112,7 +1112,7 @@ function phpVirtualBoxFailure(msg) {
  * @param {Date} expire - when cookie should expire
  */
 function vboxSetCookie(k,v,expire) {
-	var exp = (v ? (expire ? expire : new Date(2020,12,24)) : new Date().setDate(new Date().getDate() - 1));
+	var exp = (v ? (expire ? expire : new Date(Date.now() + 7 * 1000 * 60 * 60 * 24)) : new Date().setDate(new Date().getDate() - 1));
 	document.cookie = k+"="+v+"; expires="+exp.toGMTString()+"; path=/";
 	$('#vboxPane').data('vboxCookies')[k] = v;
 }
