# New ports collection makefile for:    XFree86
# Version required:     3.3.2
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.42 1998/07/03 05:01:55 cwt Exp $
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.3.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3.2/source/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3.2/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.2/source/
DISTFILES=	X332src-1.tgz X332src-2.tgz

PATCH_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/fixes/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/fixes/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3.2/fixes/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3.2/fixes/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.2/fixes/
PATCHFILES=	3.3.2-patch1 3.3.2-patch2

MAINTAINER=	jmz@FreeBSD.ORG

IS_INTERACTIVE=	yes	# configure script asks questions
NO_PACKAGE=	package available from XFree86
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist

.if defined(XDM_DES) && (${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES or NO.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
pre-fetch:
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X332src-1.tgz X332src-2.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.if ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.endif
.endif

pre-install:
	${MKDIR} /usr/X11R6
post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
