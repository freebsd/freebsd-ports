--- src/binarycookies/__main__.py.orig	2025-04-08 19:50:17 UTC
+++ src/binarycookies/__main__.py
@@ -5,6 +5,8 @@ from sys import stdout
 from typing import Type
 
 import typer
+# https://github.com/Textualize/rich/issues/271
+println = print
 from rich import print
 
 from binarycookies import load
@@ -20,6 +22,7 @@ class DateTimeEncoder(json.JSONEncoder):
 class OutputType(str, Enum):
     json = "json"
     ascii = "ascii"
+    netscape = "netscape"
 
 
 def cli(file_path: str, output: str = "json"):
@@ -27,7 +30,7 @@ def cli(file_path: str, output: str = "json"):
     with open(file_path, "rb") as f:
         cookies = load(f)
     if output == OutputType.json:
-        json.dump([cookie.model_dump() for cookie in cookies], indent=2, cls=DateTimeEncoder, fp=stdout)
+        json.dump([cookie.dict() for cookie in cookies], indent=2, cls=DateTimeEncoder, fp=stdout)
     elif output == OutputType.ascii:
         for cookie in cookies:
             print(f"Name: {cookie.name}")
@@ -38,6 +41,20 @@ def cli(file_path: str, output: str = "json"):
             print(f"Expires: {cookie.expiry_datetime.isoformat()}")
             print(f"Flag: {cookie.flag.value}")
             print("-" * 40)
+    elif output == OutputType.netscape:
+        # http://www.cookiecentral.com/faq/#3.5
+        println("# Netscape HTTP Cookie File")
+        for cookie in cookies:
+            println("%(domain)s\t%(flag)s\t%(path)s\t%(secure)s\t%(expiry)d\t%(name)s\t%(value)s" % dict(
+              domain = cookie.url,
+              flag = str(cookie.url.startswith('.')).upper(),
+              path = cookie.path,
+              secure = str('Secure' in cookie.flag.value).upper(),
+              expiry = cookie.expiry_datetime.timestamp(),
+              name = cookie.name,
+              value = cookie.value))
+    else:
+            print(f"Unsupported output format, can only do {', '.join('[green]%s[/green]' % ot.name for ot in OutputType)}.")
 
 
 def main():
