/* Change for xpbiff by Yoshikazu Yamamoto(y-yamamt@ics.es.osaka-u.ac.jp) at Oct 19, 1993 */

/* * Last edited: Sep 17 14:39 1991 (mallet) */
/*
 * $FreeBSD$
 *
 * Copyright 1991 Lionel Mallet
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Lionel MALLET not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.  Lionel MALLET makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * Lionel MALLET DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL Lionel MALLET BE LIABLE FOR ANY SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author:  Lionel Mallet - SIMULOG
 */

#include <X11/Xlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
#include <X11/StringDefs.h>
#include <sys/param.h>			/* get MAXPATHLEN if possible */
#ifndef MAXPATHLEN
#define MAXPATHLEN 256
#endif

#include <X11/Xmu/CvtCache.h>
#include <X11/xpm.h>
#include <X11/Xmu/Drawing.h>


/*
 * LocatePixmapFile - read a pixmap file using the normal defaults
 */

Pixmap LocatePixmapFile (screen, name, srcname, srcnamelen,
			    widthp, heightp, mask)
    Screen *screen;
    char *name;
    char *srcname;			/* RETURN */
    int srcnamelen;
    int *widthp, *heightp;              /* RETURN */
    Pixmap *mask;			/* RETURN */
{
    Display *dpy = DisplayOfScreen (screen);
    Window root = RootWindowOfScreen (screen);
    Bool try_plain_name = True;
    XmuCvtCache *cache = _XmuCCLookupDisplay (dpy);
    char **file_paths;
    char filename[MAXPATHLEN];
    unsigned int width, height;
    int xhot, yhot;
    int i;
    static char **split_path_string();


    /*
     * look in cache for pixmap path
     */
    if (cache) {
	if (!cache->string_to_bitmap.bitmapFilePath) {
	    XrmName xrm_name[2];
	    XrmClass xrm_class[2];
	    XrmRepresentation rep_type;
	    XrmValue value;

	    xrm_name[0] = XrmStringToName ("bitmapFilePath");
	    xrm_name[1] = NULL;
	    xrm_class[0] = XrmStringToClass ("BitmapFilePath");
	    xrm_class[1] = NULL;
	    /*
	     * XXX - warning, derefing Display * until XDisplayDatabase
	     */
	    if (!XrmGetDatabase(dpy)) {
		/* what a hack; need to initialize dpy->db */
		(void) XGetDefault (dpy, "", "");
	    }
	    if (XrmQGetResource (XrmGetDatabase(dpy), xrm_name, xrm_class, 
				 &rep_type, &value) &&
		rep_type == XrmStringToQuark(XtRString)) {
		cache->string_to_bitmap.bitmapFilePath = 
		  split_path_string (value.addr);
	    }
	}
	file_paths = cache->string_to_bitmap.bitmapFilePath;
    }


    /*
     * Search order:
     *    1.  name if it begins with / or ./
     *    2.  "each prefix in file_paths"/name
     *    3.  BITMAPDIR/name
     *    4.  name if didn't begin with / or .
     */

#ifndef BITMAPDIR
#define BITMAPDIR "/usr/include/X11/bitmaps"
#endif

    for (i = 1; i <= 4; i++) {
	char *fn = filename;
	Pixmap pixmap;
	XpmAttributes attributes;
	unsigned char *data;

	switch (i) {
	  case 1:
	    if (!(name[0] == '/' || (name[0] == '.') && name[1] == '/')) 
	      continue;
	    fn = name;
	    try_plain_name = False;
	    break;
	  case 2:
	    if (file_paths && *file_paths) {
		sprintf (filename, "%s/%s", *file_paths, name);
		file_paths++;
		i--;
		break;
	    }
	    continue;
	  case 3:
	    sprintf (filename, "%s/%s", BITMAPDIR, name);
	    break;
	  case 4:
	    if (!try_plain_name) continue;
	    fn = name;
	    break;
	}

	data = NULL;
	pixmap = None;
	if (XmuReadBitmapDataFromFile (fn, &width, &height, &data,
				       &xhot, &yhot) == BitmapSuccess) {
	    pixmap = XCreatePixmapFromBitmapData (dpy, root, (char *) data,
						  width, height,
						  (unsigned long) 1,
						  (unsigned long) 0,
						  (unsigned int) 1);
	    XFree ((char *)data);
	    if (pixmap != None) {
		if (widthp) *widthp = (int)width;
		if (heightp) *heightp = (int)height;
		if (srcname && srcnamelen > 0) {
		    strncpy (srcname, fn, srcnamelen - 1);
		    srcname[srcnamelen - 1] = '\0';
		}
		*mask = None;
		return pixmap;
	    }
	}
	attributes.visual = DefaultVisualOfScreen (screen);
	attributes.colormap = DefaultColormapOfScreen (screen);
	attributes.depth = DefaultDepthOfScreen (screen);
	attributes.colorsymbols = (ColorSymbol *)NULL;
	attributes.numsymbols = 0;
	attributes.valuemask = XpmVisual | XpmColormap | XpmDepth;
	if (pixmap == None &&
	    XpmReadPixmapFile (dpy, root, fn, &pixmap, mask,
			       &attributes) == XpmPixmapSuccess) {
	    if (widthp) *widthp = (int)attributes.width;
	    if (heightp) *heightp = (int)attributes.height;
	    if (srcname && srcnamelen > 0) {
		strncpy (srcname, fn, srcnamelen - 1);
		srcname[srcnamelen - 1] = '\0';
	    }
	    XpmFreeAttributes(&attributes);
	    return pixmap;
	}
    }
    *mask = None;
    return None;
}


/*
 * split_path_string - split a colon-separated list into its constituent
 * parts; to release, free list[0] and list.
 */
static char **split_path_string (src)
    register char *src;
{
    int nelems = 1;
    register char *dst;
    char **elemlist, **elem;

    /* count the number of elements */
    for (dst = src; *dst; dst++) if (*dst == ':') nelems++;

    /* get memory for everything */
    dst = (char *) malloc (dst - src + 1);
    if (!dst) return NULL;
    elemlist = (char **) calloc ((nelems + 1), sizeof (char *));
    if (!elemlist) {
	free (dst);
	return NULL;
    }

    /* copy to new list and walk up nulling colons and setting list pointers */
    strcpy (dst, src);
    for (elem = elemlist, src = dst; *src; src++) {
	if (*src == ':') {
	    *elem++ = dst;
	    *src = '\0';
	    dst = src + 1;
	}
    }
    *elem = dst;

    return elemlist;
}

/*
void _XmuStringToBitmapInitCache (c)
    register XmuCvtCache *c;
{
    c->string_to_bitmap.bitmapFilePath = NULL;
}

void _XmuStringToBitmapFreeCache (c)
    register XmuCvtCache *c;
{
    if (c->string_to_bitmap.bitmapFilePath) {
	if (c->string_to_bitmap.bitmapFilePath[0]) 
	  free (c->string_to_bitmap.bitmapFilePath[0]);
	free ((char *) (c->string_to_bitmap.bitmapFilePath));
    }
}
*/
