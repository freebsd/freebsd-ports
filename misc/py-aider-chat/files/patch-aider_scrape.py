--- aider/scrape.py.orig	2024-07-27 19:09:04 UTC
+++ aider/scrape.py
@@ -15,56 +15,9 @@ def install_playwright(io):
 
 
 def install_playwright(io):
-    try:
-        from playwright.sync_api import sync_playwright
+   return
 
-        has_pip = True
-    except ImportError:
-        has_pip = False
 
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
-    chromium_cmd = "playwright install --with-deps chromium".split()
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
-    io.tool_error(text)
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
@@ -89,10 +42,7 @@ class Scraper:
         `url` - the URLto scrape.
         """
 
-        if self.playwright_available:
-            content = self.scrape_with_playwright(url)
-        else:
-            content = self.scrape_with_httpx(url)
+        content = self.scrape_with_httpx(url)
 
         if not content:
             return
