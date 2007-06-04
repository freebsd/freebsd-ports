--- ../MailScanner-install-4.60.8.orig/lib/MailScanner/Message.pm	Mon Jun  4 21:52:14 2007
+++ lib/MailScanner/Message.pm	Mon Jun  4 21:52:31 2007
@@ -2,7 +2,7 @@
 #   MailScanner - SMTP E-Mail Virus Scanner
 #   Copyright (C) 2002  Julian Field
 #
-#   $Id: Message.pm 3920 2007-05-28 17:20:11Z sysjkf $
+#   $Id: Message.pm 3948 2007-06-04 18:25:09Z sysjkf $
 #
 #   This program is free software; you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
@@ -57,7 +57,7 @@
 use vars qw($VERSION);
 
 ### The package version, both in 1.23 style *and* usable by MakeMaker:
-$VERSION = substr q$Revision: 3920 $, 10;
+$VERSION = substr q$Revision: 3948 $, 10;
 
 # Attributes are
 #
@@ -126,6 +126,7 @@
 # %alltypes		set by CombineReports
 # %entity2parent	set by CreateEntitiesHelpers
 # %entity2file		set by CreateEntitiesHelpers
+# %entity2safefile	set by CreateEntitiesHelpers
 # %file2entity		set by CreateEntitiesHelpers (maps original evil names)
 # %file2safefile	set by CreateEntitiesHelpers (evil==>safe)
 # %safefile2file	set by CreateEntitiesHelpers (safe==>evil)
@@ -1528,14 +1529,17 @@
   $regexp = join('|', @escaped);
   print STDERR "Regexp is \"$regexp\"\n";
 
-  # Build a list of attachment filenames
-  my($file,@files,$entity);
+  # Build a list of attachment entities
+  my($file,@files,$entity,@entitylist);
+  $this->ListLeafEntities($this->{entity}, \@entitylist);
+
   my $totalsize = 0; #  Track total size of all attachments added to zip
-  while (defined($file = $dir->read)) {
-    next if $file =~ /^\.+$/;
+  foreach $entity (@entitylist) {
+    $file = $this->{entity2safefile}{$entity};
     next unless -f "$explodeinto/$file";
     print STDERR "Possibly adding file $file\n";
-    $entity = $this->{file2entity}{$this->{safefile2file}{$file}};
+    print STDERR "Nasty filename is " . $this->{entity2file}{$entity} . "\n";
+    #$entity = $this->{file2entity}{$this->{safefile2file}{$file}};
     print STDERR "Entity is $entity\n";
     next unless $entity;
     # Don't add the file if it's the winmail.dat file
@@ -1589,6 +1593,7 @@
 
   # Create all the Helpers for the new attachment
   $this->{entity2file}{$newentity} = $newzipname;
+  $this->{entity2safefile}{$newentity} = $safezipname;
   $this->{entity2parent}{$newentity} = 0;
   $this->{file2entity}{$newzipname} = $newentity;
   $this->{name2entity}{scalar($newentity)} = $newentity;
@@ -1597,12 +1602,12 @@
 
   # Delete the old attachments' entities
   my($attachfile, $attachentity);
-  foreach $file (@files) {
-    $attachfile = $this->{safefile2file}{$file};
-    $attachentity = $this->{file2entity}{$attachfile};
-    $this->DeleteEntity($entity, $attachentity);
+  foreach $entity (@entitylist) {
+    $attachfile = $this->{entity2safefile}{$entity};
+    #$attachentity = $this->{file2entity}{$attachfile};
+    $this->DeleteEntity($this->{entity}, $entity);
     # And the files themselves
-    unlink("$explodeinto/$file");
+    unlink("$explodeinto/$attachfile");
   }
 
 }
@@ -1890,6 +1895,27 @@
     if $workarea->{changeowner};
 }
 
+sub ListLeafEntities {
+  my($message, $entity, $entitylist) = @_;
+
+  my(@parts, $part);
+
+  # Fallen off the tree?
+  return unless $entity && defined($entity->head);
+
+  # Found a leaf node
+  if ($entity && !$entity->parts) {
+    push @$entitylist, $entity;
+    return;
+  }
+
+  # Walk down each sub-tree
+  @parts = $entity->parts;
+  foreach $part (@parts) {
+    ListLeafEntities($message, $part, $entitylist);
+  }
+}
+
 # Delete a given entity from the MIME entity tree.
 # Have to walk the entire tree to do this.
 # Bail out as soon as we've found it.
@@ -2860,6 +2886,7 @@
 
   # Put something useless in the 2 hashes so that they exist.
   $this->{entity2file}{""} = 0;
+  $this->{entity2safefile}{""} = 0;
   $this->{entity2parent}{""} = 0;
   $this->{file2entity}{""} = $this->{entity}; # Root of this message
   $this->{name2entity}{""} = 0;
@@ -2870,6 +2897,7 @@
                                  $this->{file2safefile},
                                  $this->{safefile2file},
                                  $this->{entity2file},
+                                 $this->{entity2safefile},
                                  $this->{name2entity});
   #print STDERR "In CreateEntitiesHelpers, this = $this\n";
   #print STDERR "In CreateEntitiesHelpers, this entity = " .
@@ -2903,7 +2931,7 @@
 # This is recursive. This is a class function, not a normal method.
 sub BuildFile2EntityAndEntity2File {
   my($entity, $file2entity, $file2safefile, $safefile2file, $entity2file,
-     $name2entity) = @_;
+     $entity2safefile, $name2entity) = @_;
 
   # Build the conversion hash from scalar(entity) --> real entity object
   # Need to do this as objects cannot be hash keys.
@@ -2929,6 +2957,7 @@
   if ($headfile) {
     $file2entity->{$headfile} = $entity if !$file2entity->{$headfile};
     $file2safefile->{$headfile} = $path;
+    $entity2safefile->{$entity} = $path;
     $safefile2file->{$path}     = $headfile;
     #print STDERR "File2SafeFile (\"$headfile\") = \"$path\"\n";
   }
@@ -2937,7 +2966,8 @@
   @parts = $entity->parts;
   foreach $part (@parts) {
     BuildFile2EntityAndEntity2File($part, $file2entity, $file2safefile,
-                                   $safefile2file, $entity2file, $name2entity);
+                                   $safefile2file, $entity2file,
+                                   $entity2safefile, $name2entity);
   }
 }
 
