-- bool(os.getenv('IsDev', False)) is true for any non-empty string, so
-- the IsDev=False of the shipped .env.example started the service in
-- development mode. Also let DEDUP_ENV point at the dotenv file.
--
-- TODO: reported upstream, drop the IsDev part when it lands.

--- src/conf.py.orig	2026-11-07 09:38:16 UTC
+++ src/conf.py
@@ -10,7 +10,7 @@ import torch
 # import ssl
 # ssl._create_default_https_context = ssl._create_unverified_context
 
-dotenv.load_dotenv()
+dotenv.load_dotenv(os.getenv('DEDUP_ENV') or None)
 
 from util import log
 
@@ -246,8 +246,8 @@ class envs:
 #------------------------------------------------------------------------
 class envs:
 	version = '0.3.6'
-	isDev = False if isDock else bool(os.getenv('IsDev', False))
-	isDevUI = False if isDock else bool(os.getenv('IsDevUI', False))
+	isDev = False if isDock else os.getenv('IsDev', '').lower() in ('1', 'true', 'yes', 'on')
+	isDevUI = False if isDock else os.getenv('IsDevUI', '').lower() in ('1', 'true', 'yes', 'on')
 	isDock = False if not isDock else True
 	envImmichPath:str = os.getenv('IMMICH_PATH', '')    # original from .env
 	envImmichThumb:str = os.getenv('IMMICH_THUMB', '')  # original from .env
