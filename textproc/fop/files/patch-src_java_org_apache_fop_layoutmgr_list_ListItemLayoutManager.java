--- src/java/org/apache/fop/layoutmgr/list/ListItemLayoutManager.java.orig	2015-05-26 08:03:48 UTC
+++ src/java/org/apache/fop/layoutmgr/list/ListItemLayoutManager.java
@@ -393,7 +393,7 @@ public class ListItemLayoutManager exten
             int breakClass = EN_AUTO;
             KnuthElement endEl = elementLists[0].size() > 0 ? (KnuthElement) elementLists[0].get(end[0])
                     : null;
-            Position originalLabelPosition = endEl != null ? endEl.getPosition().getPosition() : null;
+            Position originalLabelPosition = (endEl != null && endEl.getPosition() != null) ? endEl.getPosition().getPosition() : null;
             if (endEl instanceof KnuthPenalty) {
                 additionalPenaltyHeight = endEl.getWidth();
                 stepPenalty = endEl.getPenalty() == -KnuthElement.INFINITE ? -KnuthElement.INFINITE : Math
@@ -402,7 +402,7 @@ public class ListItemLayoutManager exten
                         ((KnuthPenalty) endEl).getBreakClass());
             }
             endEl = elementLists[1].size() > 0 ? (KnuthElement) elementLists[1].get(end[1]) : null;
-            Position originalBodyPosition = endEl != null ? endEl.getPosition().getPosition() : null;
+            Position originalBodyPosition = (endEl != null && endEl.getPosition() != null) ? endEl.getPosition().getPosition() : null;
             if (endEl instanceof KnuthPenalty) {
                 additionalPenaltyHeight = Math.max(
                         additionalPenaltyHeight, endEl.getWidth());
