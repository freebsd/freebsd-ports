--- src/scripts/extract_syscall.py.orig	2020-02-23 00:00:42 UTC
+++ src/scripts/extract_syscall.py
@@ -41,6 +41,8 @@ if __name__ == "__main__":
 
     if platform.system() == 'Linux':
         regex = re.compile(r"#define\s+(__NR_)(\w+)\s+(\d+)")
+    elif platform.system() == 'FreeBSD':
+        regex = re.compile(r"#define\s+(__NR_)(\w+)\s+(\d+)")
     elif platform.system() == 'Darwin':
         regex = re.compile(r"#define\s+(SYS_)(\w+)\s+(\d+)")
     else:
