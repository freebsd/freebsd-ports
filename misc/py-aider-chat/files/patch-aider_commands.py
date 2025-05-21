--- aider/commands.py.orig	2025-04-14 23:24:32 UTC
+++ aider/commands.py
@@ -21,7 +21,7 @@ from aider.run_cmd import run_cmd
 from aider.llm import litellm
 from aider.repo import ANY_GIT_ERROR
 from aider.run_cmd import run_cmd
-from aider.scrape import Scraper, install_playwright
+from aider.scrape import Scraper
 from aider.utils import is_image_file
 
 from .dump import dump  # noqa: F401
@@ -219,14 +219,6 @@ class Commands:
             return
 
         self.io.tool_output(f"Scraping {url}...")
-        if not self.scraper:
-            res = install_playwright(self.io)
-            if not res:
-                self.io.tool_warning("Unable to initialize playwright.")
-
-            self.scraper = Scraper(
-                print_error=self.io.tool_error, playwright_available=res, verify_ssl=self.verify_ssl
-            )
 
         content = self.scraper.scrape(url) or ""
         content = f"Here is the content of {url}:\n\n" + content
