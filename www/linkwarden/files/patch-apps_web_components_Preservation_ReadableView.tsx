--- apps/web/components/Preservation/ReadableView.tsx.orig	2026-11-10 18:23:37 UTC
+++ apps/web/components/Preservation/ReadableView.tsx
@@ -27,13 +27,18 @@ import DangerousLinkWarningModal from "@/components/Mo
 import { useUser } from "@linkwarden/router/user";
 import { handleLinkAnchorClick } from "@/lib/client/openLink";
 import DangerousLinkWarningModal from "@/components/ModalContent/DangerousLinkWarningModal";
-import { Caveat } from "next/font/google";
-import { Bentham } from "next/font/google";
+import localFont from "next/font/local";
 import { Separator } from "../ui/separator";
 import { Button } from "../ui/button";
 
-const caveat = Caveat({ subsets: ["latin"] });
-const bentham = Bentham({ subsets: ["latin"], weight: "400" });
+const caveat = localFont({
+  src: "../../fonts/Caveat-Variable.ttf",
+  weight: "400 700",
+});
+const bentham = localFont({
+  src: "../../fonts/Bentham-Regular.ttf",
+  weight: "400",
+});
 
 type Props = {
   link: LinkIncludingShortenedCollectionAndTags;
