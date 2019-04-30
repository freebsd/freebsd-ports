/**
 * D header file for libinotify (incomplete)
 */

module freebsd_inotify;

import core.stdc.stdint;

struct inotify_event
{
	int wd;          /* Watch descriptor.  */
	uint32_t mask;   /* Watch mask.  */
	uint32_t cookie; /* Cookie to synchronize two events.  */
	uint32_t len;    /* Length (including NULLs) of name.  */
	char[0] name;     /* Name.  */

	@disable this(this);
};


/* Supported events suitable for MASK parameter of INOTIFY_ADD_WATCH.  */
enum IN_ACCESS =      0x00000001; /* File was accessed.  */
enum IN_MODIFY =      0x00000002; /* File was modified.  */
enum IN_ATTRIB =      0x00000004; /* Metadata changed.  */
enum IN_CLOSE_WRITE = 0x00000008; /* Writtable file was closed.  */
enum IN_CLOSE_NOWRITE = 0x00000010; /* Unwrittable file closed.  */
enum IN_CLOSE =       (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE); /* Close.  */
enum IN_OPEN  =       0x00000020; /* File was opened.  */
enum IN_MOVED_FROM =  0x00000040; /* File was moved from X.  */
enum IN_MOVED_TO =    0x00000080; /* File was moved to Y.  */
enum IN_MOVE =        (IN_MOVED_FROM | IN_MOVED_TO); /* Moves.  */
enum IN_CREATE =      0x00000100; /* Subfile was created.  */
enum IN_DELETE =      0x00000200; /* Subfile was deleted.  */
enum IN_DELETE_SELF = 0x00000400; /* Self was deleted.  */
enum IN_MOVE_SELF =   0x00000800; /* Self was moved.  */

/* Additional events and flags. Some of these flags are unsupported,
      but still should be present */
enum IN_UNMOUNT =     0x00002000;    /* Backing fs was unmounted.  */
enum IN_Q_OVERFLOW =  0x00004000;    /* Event queued overflowed.  */
enum IN_IGNORED =     0x00008000;    /* File was ignored.  */

enum IN_ONLYDIR =     0x01000000;    /* Only watch the path if it is a
                                        directory.  */
enum IN_DONT_FOLLOW = 0x02000000;    /* Do not follow a sym link.  */
enum IN_EXCL_UNLINK = 0x04000000;    /* Exclude events on unlinked
                                        objects.  */
enum IN_MASK_ADD =    0x20000000;    /* Add to the mask of an already
                                        existing watch.  */
enum IN_ISDIR =       0x40000000;    /* Event occurred against dir.  */
enum IN_ONESHOT =     0x80000000;    /* Only send event once.  */


/* Create and initialize inotify-kqueue instance. */
extern (C) int inotify_init ();

/* Create and initialize inotify-kqueue instance. */
extern (C) int inotify_init1 (int flags);

/* Add watch of object NAME to inotify-kqueue instance FD. Notify about
      events specified by MASK. */
extern (C) int inotify_add_watch (int fd, const char *name, uint32_t mask);

/* Remove the watch specified by WD from the inotify instance FD. */
extern (C) int inotify_rm_watch (int fd, int wd);

/* Libinotify specific. Set inotify instance parameter. */
extern (C) int inotify_set_param (int fd, int param, intptr_t value);

