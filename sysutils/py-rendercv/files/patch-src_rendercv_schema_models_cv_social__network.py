--- src/rendercv/schema/models/cv/social_network.py.orig	1970-01-01 00:00:00 UTC
+++ src/rendercv/schema/models/cv/social_network.py
@@ -10,7 +10,7 @@ url_validator = pydantic.TypeAdapter(pydantic.HttpUrl)
 from ..base import BaseModelWithoutExtraKeys
 
 url_validator = pydantic.TypeAdapter(pydantic.HttpUrl)
-type SocialNetworkName = Literal[
+SocialNetworkName = Literal[
     "LinkedIn",
     "GitHub",
     "GitLab",
@@ -28,7 +28,7 @@ type SocialNetworkName = Literal[
     "X",
     "Bluesky",
 ]
-available_social_networks = get_args(SocialNetworkName.__value__)
+#available_social_networks = get_args(SocialNetworkName.__value__)
 url_dictionary: dict[SocialNetworkName, str] = {
     "LinkedIn": "https://linkedin.com/in/",
     "GitHub": "https://github.com/",
