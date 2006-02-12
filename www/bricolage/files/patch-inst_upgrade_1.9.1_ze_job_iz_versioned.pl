--- inst/upgrade/1.9.1/ze_job_iz_versioned.pl.orig	Tue Dec 20 07:37:14 2005
+++ inst/upgrade/1.9.1/ze_job_iz_versioned.pl	Thu Feb  9 02:17:16 2006
@@ -18,7 +18,9 @@ do_sql
     # set, even though they've been published.
     q{UPDATE story
       SET    published_version = COALESCE(s.published_version, s.current_version),
-             publish_status    = '1'
+             publish_status    = '1',
+             first_publish_date = COALESCE(s.first_publish_date, s.publish_date, CURRENT_TIMESTAMP),
+             publish_date = COALESCE(s.publish_date, s.first_publish_date, CURRENT_TIMESTAMP)
       FROM   job j, story s
       WHERE  story.id = s.id
              AND j.story_instance__id = s.id
@@ -30,7 +32,9 @@ do_sql
 
     q{UPDATE media
       SET    published_version = COALESCE(m.published_version, m.current_version),
-             publish_status    = '1'
+             publish_status    = '1',
+             first_publish_date = COALESCE(m.first_publish_date, m.publish_date, CURRENT_TIMESTAMP),
+             publish_date = COALESCE(m.publish_date, m.first_publish_date, CURRENT_TIMESTAMP)
       FROM   job j, media m
       WHERE  media.id = m.id
              AND j.media_instance__id = m.id
