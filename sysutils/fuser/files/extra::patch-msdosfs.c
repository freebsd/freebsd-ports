--- msdosfs.c.orig	2009-06-07 12:53:34.000000000 +0400
+++ msdosfs.c	2009-06-07 12:57:41.000000000 +0400
@@ -72,6 +72,7 @@
 	struct denode		denode;
 	u_long			dirsperblk;
 	struct msdosfsmount	mnt;
+	struct vnode		devvp;
 	int			fileid;
 	int			ret;
 
@@ -90,7 +91,13 @@
 		return 1;
 	}
 
-	fsp->dev = dev2udev(denode.de_dev);
+	ret = KVM_READ(kd, mnt.pm_devvp, &devvp, sizeof(devvp));
+	if (ret != sizeof(devvp)) {
+		warnx("can't read vnode info at %p\n", (void *)mnt.pm_devvp);
+		return 1;
+	}
+
+	fsp->dev = dev2udev(devvp.v_rdev);
 
 	/*
 	 * XXX -
