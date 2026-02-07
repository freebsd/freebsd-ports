--- aider/scrape.py.orig	2025-05-09 22:41:18 UTC
+++ aider/scrape.py
@@ -92,7 +92,7 @@ class Scraper:
         else:
             self.print_error = print
 
-        self.playwright_available = playwright_available
+        self.playwright_available = False
         self.verify_ssl = verify_ssl
 
     def scrape(self, url):
@@ -103,10 +103,7 @@ class Scraper:
         `url` - the URL to scrape.
         """
 
-        if self.playwright_available:
-            content, mime_type = self.scrape_with_playwright(url)
-        else:
-            content, mime_type = self.scrape_with_httpx(url)
+        content, mime_type = self.scrape_with_httpx(url)
 
         if not content:
             self.print_error(f"Failed to retrieve content from {url}")
@@ -138,58 +135,6 @@ class Scraper:
             ]
             return any(re.search(pattern, content, re.IGNORECASE) for pattern in html_patterns)
         return False
-
-    # Internals...
-    def scrape_with_playwright(self, url):
-        import playwright  # noqa: F401
-        from playwright.sync_api import Error as PlaywrightError
-        from playwright.sync_api import TimeoutError as PlaywrightTimeoutError
-        from playwright.sync_api import sync_playwright
-
-        with sync_playwright() as p:
-            try:
-                browser = p.chromium.launch()
-            except Exception as e:
-                self.playwright_available = False
-                self.print_error(str(e))
-                return None, None
-
-            try:
-                context = browser.new_context(ignore_https_errors=not self.verify_ssl)
-                page = context.new_page()
-
-                user_agent = page.evaluate("navigator.userAgent")
-                user_agent = user_agent.replace("Headless", "")
-                user_agent = user_agent.replace("headless", "")
-                user_agent += " " + aider_user_agent
-
-                page.set_extra_http_headers({"User-Agent": user_agent})
-
-                response = None
-                try:
-                    response = page.goto(url, wait_until="networkidle", timeout=5000)
-                except PlaywrightTimeoutError:
-                    print(f"Page didn't quiesce, scraping content anyway: {url}")
-                    response = None
-                except PlaywrightError as e:
-                    self.print_error(f"Error navigating to {url}: {str(e)}")
-                    return None, None
-
-                try:
-                    content = page.content()
-                    mime_type = None
-                    if response:
-                        content_type = response.header_value("content-type")
-                        if content_type:
-                            mime_type = content_type.split(";")[0]
-                except PlaywrightError as e:
-                    self.print_error(f"Error retrieving page content: {str(e)}")
-                    content = None
-                    mime_type = None
-            finally:
-                browser.close()
-
-        return content, mime_type
 
     def scrape_with_httpx(self, url):
         import httpx
