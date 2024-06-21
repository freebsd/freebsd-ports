--- aider/scrape.py.orig	2024-06-17 03:58:03 UTC
+++ aider/scrape.py
@@ -7,7 +7,6 @@ from bs4 import BeautifulSoup
 import playwright
 import pypandoc
 from bs4 import BeautifulSoup
-from playwright.sync_api import sync_playwright
 
 from aider import __version__, urls
 from aider.dump import dump  # noqa: F401
@@ -44,14 +43,11 @@ class Scraper:
         """
         Scrape a url and turn it into readable markdown.
 
-        `url` - the URLto scrape.
+        `url` - the URL to scrape.
         """
         self.try_playwright()
 
-        if self.playwright_available:
-            content = self.scrape_with_playwright(url)
-        else:
-            content = self.scrape_with_httpx(url)
+        content = self.scrape_with_httpx(url)
 
         if not content:
             return
@@ -64,51 +60,6 @@ class Scraper:
         return content
 
     # Internals...
-    def scrape_with_playwright(self, url):
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
-        with sync_playwright() as p:
-            try:
-                p.chromium.launch()
-                self.playwright_available = True
-            except Exception:
-                self.playwright_available = False
-
-    def get_playwright_instructions(self):
-        if self.playwright_available in (True, None):
-            return
-        if self.playwright_instructions_shown:
-            return
-
-        self.playwright_instructions_shown = True
-        return PLAYWRIGHT_INFO
 
     def scrape_with_httpx(self, url):
         headers = {"User-Agent": f"Mozilla./5.0 ({aider_user_agent})"}
