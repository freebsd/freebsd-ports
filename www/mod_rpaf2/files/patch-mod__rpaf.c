From e93902533dd89ba6c77cea90e4e2c7d762650126 Mon Sep 17 00:00:00 2001
From: Geoffroy Desvernay <dgeo@centrale-marseille.fr>
Date: Mon, 12 Dec 2016 10:01:14 +0100
Subject: [PATCH] Fix warning with clang

Fix this warning on FreeBSD 11 (clang cc by default)
./apxs.sh -c -n mod_rpaf.so mod_rpaf.c
/usr/local/share/apr/build-1/libtool --silent --mode=compile cc -prefer-pic -O2 -pipe -I/usr/local/include -DLIBICONV_PLUG -fstack-protector -fno-strict-aliasing    -I/usr/local/include/apache24  -I/usr/local/include/apr-1   -I/usr/local/include/apr-1 -I/usr/local/include -I/usr/local/include/db5 -I/usr/include  -c -o mod_rpaf.lo mod_rpaf.c && touch mod_rpaf.slo
mod_rpaf.c:117:18: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
        if (mask = ap_strchr(ip, '/')) {
            ~~~~~^~~~~~~~~~~~~~~~~~~~
mod_rpaf.c:117:18: note: place parentheses around the assignment to silence this warning
        if (mask = ap_strchr(ip, '/')) {
                 ^
            (                        )
mod_rpaf.c:117:18: note: use '==' to turn this assignment into an equality comparison
        if (mask = ap_strchr(ip, '/')) {
                 ^
                 ==
1 warning generated.
--- mod_rpaf.c.orig	2014-09-03 06:41:36 UTC
+++ mod_rpaf.c
@@ -114,7 +114,7 @@ static const char *rpaf_set_proxy_ip(cmd
 
     if (rpaf_looks_like_ip(proxy_ip)) {
         ip = apr_pstrdup(cmd->temp_pool, proxy_ip);
-        if (mask = ap_strchr(ip, '/')) {
+        if ((mask = ap_strchr(ip, '/'))) {
             *mask++ = '\0';
         }
         sub = (apr_ipsubnet_t **)apr_array_push(cfg->proxy_ips);
