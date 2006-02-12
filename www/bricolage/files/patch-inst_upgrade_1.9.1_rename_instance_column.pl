--- inst/upgrade/1.9.1/rename_instance_column.pl.orig	Tue Oct  4 05:30:43 2005
+++ inst/upgrade/1.9.1/rename_instance_column.pl	Thu Feb  9 02:17:16 2006
@@ -49,7 +49,7 @@ do_sql
         ALTER TABLE media_container_tile
         ADD CONSTRAINT fk_mc_tile__related_story
         FOREIGN KEY (related_story__id)
-        REFERENCES media(id) ON DELETE CASCADE
+        REFERENCES story(id) ON DELETE CASCADE
     },
 
     # Add FK constraint for mediacontainer_tile.related_media__id
