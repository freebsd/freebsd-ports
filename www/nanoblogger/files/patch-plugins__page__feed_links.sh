--- ./plugins/page/feed_links.sh.orig	2007-02-05 00:12:00.000000000 +0100
+++ ./plugins/page/feed_links.sh	2009-06-22 09:31:59.000000000 +0200
@@ -16,14 +16,14 @@
 		NB_AtomLink="${BASE_URL}atom.$NB_SYND_FILETYPE"
 		NB_AtomTitle="Atom $NB_AtomVer"
 	fi
-	NB_AtomAltLink=$(
+	NB_AtomAltLink=`
 	cat <<-EOF
 		<link rel="alternate" type="application/atom+xml"
 			title="$NB_AtomTitle"
 			href="$NB_AtomLink"
 		/>
 	EOF
-	)
+	`
 fi
 
 # RSS 2.0
@@ -36,14 +36,14 @@
 		NB_RSS2Link="${BASE_URL}rss.$NB_SYND_FILETYPE"
 		NB_RSS2Title="RSS $NB_RSS2Ver"
 	fi
-	NB_RSS2AltLink=$(
+	NB_RSS2AltLink=`
 	cat <<-EOF
 		<link rel="alternate" type="application/rss+xml"
 			title="$NB_RSS2Title"
 			href="$NB_RSS2Link"
 		/>
 	EOF
-	)
+	`
 fi
 
 # RSS 1.0
@@ -56,13 +56,13 @@
 		NB_RSSLink="${BASE_URL}index.$NB_SYND_FILETYPE"
 		NB_RSSTitle="RSS $NB_RSSVer"
 	fi
-	NB_RSSAltLink=$(
+	NB_RSSAltLink=`
 	cat <<-EOF
 		<link rel="alternate" type="application/rss+xml"
 			title="$NB_RSSTitle"
 			href="$NB_RSSLink"
 		/>
 	EOF
-	)
+	`
 fi
 
