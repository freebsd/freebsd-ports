--- aider/scrape.py.orig	2024-07-04 14:23:32 UTC
+++ aider/scrape.py
@@ -3,9 +3,7 @@ import sys
 import re
 import sys
 
-import playwright
 import pypandoc
-from playwright.sync_api import sync_playwright
 
 from aider import __version__, urls
 from aider.dump import dump  # noqa: F401
@@ -42,14 +40,10 @@ class Scraper:
         """
         Scrape a url and turn it into readable markdown.
 
-        `url` - the URLto scrape.
+        `url` - the URL to scrape.
         """
-        self.try_playwright()
 
-        if self.playwright_available:
-            content = self.scrape_with_playwright(url)
-        else:
-            content = self.scrape_with_httpx(url)
+        content = self.scrape_with_httpx(url)
 
         if not content:
             return
@@ -62,50 +56,8 @@ class Scraper:
 
     # Internals...
     def scrape_with_playwright(self, url):
-        with sync_playwright() as p:
-            try:
-                browser = p.chromium.launch()
-            except Exception as e:
-                self.playwright_available = False
-                self.print_error(e)
-                return
-
-            page = browser.new_page()
-
-            user_agent = page.evaluate("navigator.userAgent")
-            user_agent = user_agent.replace("Headless", "")
-            user_agent = user_agent.replace("headless", "")
-            user_agent += " " + aider_user_agent
-
-            page = browser.new_page(user_agent=user_agent)
-            try:
-                page.goto(url, wait_until="networkidle", timeout=5000)
-            except playwright._impl._errors.TimeoutError:
-                pass
-            content = page.content()
-            browser.close()
-
-        return content
-
-    def try_playwright(self):
-        if self.playwright_available is not None:
-            return
-
-        try:
-            with sync_playwright() as p:
-                p.chromium.launch()
-                self.playwright_available = True
-        except Exception:
             self.playwright_available = False
-
-    def get_playwright_instructions(self):
-        if self.playwright_available in (True, None):
             return
-        if self.playwright_instructions_shown:
-            return
-
-        self.playwright_instructions_shown = True
-        return PLAYWRIGHT_INFO
 
     def scrape_with_httpx(self, url):
         import httpx
