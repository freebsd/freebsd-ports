--- lib/gcstar/GCPlugins/GCmusics/GCDiscogs.pm.orig	2008-12-29 14:20:09.000000000 +0100
+++ lib/gcstar/GCPlugins/GCmusics/GCDiscogs.pm	2008-12-29 14:23:04.000000000 +0100
@@ -165,6 +165,7 @@
             $self->{curInfo}->{origin} =~ s/,$//;
             $self->{curInfo}->{format} = $xml->{release}->{formats}->{format}->{name};
             $self->{curInfo}->{format} =~ s/,$//;
+            $self->{curInfo}->{web} = "http://www.discogs.com/release/" . $xml->{release}->{id};
         }
     }
 
