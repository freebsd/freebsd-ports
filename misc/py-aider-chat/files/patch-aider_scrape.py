--- aider/scrape.py.orig	2024-09-09 10:28:04 UTC
+++ aider/scrape.py
@@ -15,57 +15,8 @@ def install_playwright(io):
 
 
 def install_playwright(io):
-    try:
-        from playwright.sync_api import sync_playwright
+    return False
 
-        has_pip = True
-    except ImportError:
-        has_pip = False
-
-    try:
-        with sync_playwright() as p:
-            p.chromium.launch()
-            has_chromium = True
-    except Exception:
-        has_chromium = False
-
-    if has_pip and has_chromium:
-        return True
-
-    pip_cmd = utils.get_pip_install(["aider-chat[playwright]"])
-    chromium_cmd = "-m playwright install --with-deps chromium"
-    chromium_cmd = [sys.executable] + chromium_cmd.split()
-
-    cmds = ""
-    if not has_pip:
-        cmds += " ".join(pip_cmd) + "\n"
-    if not has_chromium:
-        cmds += " ".join(chromium_cmd) + "\n"
-
-    text = f"""For the best web scraping, install Playwright:
-
-{cmds}
-See {urls.enable_playwright} for more info.
-"""
-
-    io.tool_output(text)
-    if not io.confirm_ask("Install playwright?", default="y"):
-        return
-
-    if not has_pip:
-        success, output = utils.run_install(pip_cmd)
-        if not success:
-            io.tool_error(output)
-            return
-
-    success, output = utils.run_install(chromium_cmd)
-    if not success:
-        io.tool_error(output)
-        return
-
-    return True
-
-
 class Scraper:
     pandoc_available = None
     playwright_available = None
@@ -82,7 +33,7 @@ class Scraper:
         else:
             self.print_error = print
 
-        self.playwright_available = playwright_available
+        self.playwright_available = False
         self.verify_ssl = verify_ssl
 
     def scrape(self, url):
@@ -93,10 +44,7 @@ class Scraper:
         `url` - the URL to scrape.
         """
 
-        if self.playwright_available:
-            content, mime_type = self.scrape_with_playwright(url)
-        else:
-            content, mime_type = self.scrape_with_httpx(url)
+        content, mime_type = self.scrape_with_httpx(url)
 
         if not content:
             self.print_error(f"Failed to retrieve content from {url}")
@@ -130,56 +78,6 @@ class Scraper:
         return False
 
     # Internals...
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
-                    self.print_error(f"Timeout while loading {url}")
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
-
     def scrape_with_httpx(self, url):
         import httpx
 
