--- src/rendercv/schema/models/cv/social_network.py.orig	2026-03-11 16:50:40 UTC
+++ src/rendercv/schema/models/cv/social_network.py
@@ -10,7 +10,7 @@ url_validator = pydantic.TypeAdapter[pydantic.HttpUrl]
 from ..base import BaseModelWithoutExtraKeys
 
 url_validator = pydantic.TypeAdapter[pydantic.HttpUrl](pydantic.HttpUrl)
-type SocialNetworkName = Literal[
+SocialNetworkName = Literal[
     "LinkedIn",
     "GitHub",
     "GitLab",
@@ -29,7 +29,7 @@ type SocialNetworkName = Literal[
     "Bluesky",
     "Reddit",
 ]
-available_social_networks = get_args(SocialNetworkName.__value__)
+#available_social_networks = get_args(SocialNetworkName.__value__)
 url_dictionary: dict[SocialNetworkName, str] = {
     "LinkedIn": "https://linkedin.com/in/",
     "GitHub": "https://github.com/",
