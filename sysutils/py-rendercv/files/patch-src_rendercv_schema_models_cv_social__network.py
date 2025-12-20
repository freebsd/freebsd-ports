--- src/rendercv/schema/models/cv/social_network.py.orig	2025-12-19 21:44:26 UTC
+++ src/rendercv/schema/models/cv/social_network.py
@@ -10,7 +10,7 @@ url_validator = pydantic.TypeAdapter(pydantic.HttpUrl)
 from ..base import BaseModelWithoutExtraKeys
 
 url_validator = pydantic.TypeAdapter(pydantic.HttpUrl)
-type SocialNetworkName = Literal[
+SocialNetworkName = Literal[
     "LinkedIn",
     "GitHub",
     "GitLab",
@@ -27,7 +27,7 @@ type SocialNetworkName = Literal[
     "Leetcode",
     "X",
 ]
-available_social_networks = get_args(SocialNetworkName.__value__)
+#available_social_networks = get_args(SocialNetworkName.__value__)
 url_dictionary: dict[SocialNetworkName, str] = {
     "LinkedIn": "https://linkedin.com/in/",
     "GitHub": "https://github.com/",
