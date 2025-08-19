--- searx/version.py.orig	2025-08-19 19:13:19 UTC
+++ searx/version.py
@@ -91,15 +91,6 @@ def get_information():
     git_url = GIT_URL
     git_branch = GIT_BRANCH
 
-    try:
-        version_string, version_tag, docker_tag = get_git_version()
-    except subprocess.CalledProcessError as ex:
-        logger.error("Error while getting the version: %s", ex.stderr)
-    try:
-        git_url, git_branch = get_git_url_and_branch()
-    except subprocess.CalledProcessError as ex:
-        logger.error("Error while getting the git URL & branch: %s", ex.stderr)
-
     return version_string, version_tag, docker_tag, git_url, git_branch
 
 
