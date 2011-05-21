--- setup.py.orig	2011-05-01 10:30:11.000000000 +0200
+++ setup.py	2011-05-01 10:30:22.000000000 +0200
@@ -386,7 +386,7 @@
 
 if __name__ == "__main__":
     pdfdocs = glob.glob(os.path.join("docs", "*.pdf"))
-    htmldoc = [os.path.join("docs", "html")]
+    htmldoc = [os.path.join("docs", "xhtml")]
 
     setup(name="dblatex",
         version=get_version(),
