--- aider/commands.py.orig	2025-02-24 10:27:07 UTC
+++ aider/commands.py
@@ -20,7 +20,7 @@ from aider.run_cmd import run_cmd
 from aider.llm import litellm
 from aider.repo import ANY_GIT_ERROR
 from aider.run_cmd import run_cmd
-from aider.scrape import Scraper, install_playwright
+from aider.scrape import Scraper
 from aider.utils import is_image_file
 
 from .dump import dump  # noqa: F401
@@ -172,12 +172,8 @@ class Commands:
 
         self.io.tool_output(f"Scraping {url}...")
         if not self.scraper:
-            res = install_playwright(self.io)
-            if not res:
-                self.io.tool_warning("Unable to initialize playwright.")
-
             self.scraper = Scraper(
-                print_error=self.io.tool_error, playwright_available=res, verify_ssl=self.verify_ssl
+                print_error=self.io.tool_error, playwright_available=False, verify_ssl=self.verify_ssl
             )
 
         content = self.scraper.scrape(url) or ""
