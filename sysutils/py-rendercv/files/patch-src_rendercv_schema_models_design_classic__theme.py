--- src/rendercv/schema/models/design/classic_theme.py.orig	2026-04-11 19:19:45 UTC
+++ src/rendercv/schema/models/design/classic_theme.py
@@ -7,10 +7,10 @@ from rendercv.schema.models.design.typst_dimension imp
 from rendercv.schema.models.design.font_family import FontFamily as FontFamilyType
 from rendercv.schema.models.design.typst_dimension import TypstDimension
 
-type Bullet = Literal["●", "•", "◦", "-", "◆", "★", "■", "—", "○"]
-type BodyAlignment = Literal["left", "justified", "justified-with-no-hyphenation"]
-type Alignment = Literal["left", "center", "right"]
-type SectionTitleType = Literal[
+Bullet = Literal["●", "•", "◦", "-", "◆", "★", "■", "—", "○"]
+BodyAlignment = Literal["left", "justified", "justified-with-no-hyphenation"]
+Alignment = Literal["left", "center", "right"]
+SectionTitleType = Literal[
     "with_partial_line",
     "with_full_line",
     "without_line",
@@ -20,8 +20,8 @@ type SectionTitleType = Literal[
     "centered_with_centered_partial_line",
     "centered_with_full_line",
 ]
-type PhoneNumberFormatType = Literal["national", "international", "E164"]
-type PageSize = Literal["a4", "a5", "us-letter", "us-executive"]
+PhoneNumberFormatType = Literal["national", "international", "E164"]
+PageSize = Literal["a4", "a5", "us-letter", "us-executive"]
 
 length_common_description = (
     "It can be specified with units (cm, in, pt, mm, em). For example, `0.1cm`."
