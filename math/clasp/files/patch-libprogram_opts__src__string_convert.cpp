--- ./libprogram_opts/src/string_convert.cpp.orig	2014-08-12 18:47:21.000000000 +0300
+++ ./libprogram_opts/src/string_convert.cpp	2014-08-27 14:59:59.000000000 +0300
@@ -94,7 +94,7 @@
 		err = (char*)x+2;
 	}
 	else if (*x != '-') {
-		out = std::strtoul(x, &err, detectBase(x));
+		out = strtoul(x, &err, detectBase(x));
 		if (out == ULONG_MAX && errno == ERANGE) { err = (char*)x; }
 	}
 	else { err = (char*)x; }
@@ -191,7 +191,7 @@
 	if (t) { out = temp; return t; }
 	if (empty(x, errPos) || *x == '-') { return 0; }
 	char* err;
-	out = std::strtoull(x, &err, detectBase(x));
+	out = strtoull(x, &err, detectBase(x));
 	return parsed(err != x, err, errPos);
 }
 std::string& xconvert(std::string& out, long long x) {
