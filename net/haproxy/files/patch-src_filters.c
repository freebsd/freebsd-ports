--- src/filters.c.orig	2021-10-03 17:40:24 UTC
+++ src/filters.c
@@ -475,7 +475,7 @@ flt_stream_start(struct stream *s)
 	}
 	if (strm_li(s) && (strm_li(s)->analysers & AN_REQ_FLT_START_FE)) {
 		s->req.flags |= CF_FLT_ANALYZE;
-		s->req.analysers |= AN_RES_FLT_END;
+		s->req.analysers |= AN_REQ_FLT_END;
 	}
 	return 0;
 }
