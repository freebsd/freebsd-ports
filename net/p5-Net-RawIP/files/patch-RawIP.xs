
$FreeBSD$

--- RawIP.xs.orig	Mon Aug 23 16:38:46 2004
+++ RawIP.xs	Mon Aug 23 16:39:04 2004
@@ -440,7 +440,7 @@
        sv_catpvn(ip_opts,SvPV(*av_fetch(opts,i+2,0),l),
                          SvCUR(*av_fetch(opts,i+2,0)));
        break;
-       default:
+       default: break;
        }
     }
        c = 0;
@@ -539,7 +539,7 @@
        sv_catpvn(ip_opts,SvPV(*av_fetch(opts,i+2,0),l),
                          SvCUR(*av_fetch(opts,i+2,0)));
        break;
-       default:
+       default: break;
        }
     }
        c = 0;
