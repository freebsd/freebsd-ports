# New ports collection makefile for:	gopod
# Date created:				4 April 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	gtk-

COMMENT=	GTK Utility to cap/uncap an iPod

MASTERDIR=	${.CURDIR}/../gopod

USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

RESTRICTED=	"Unclear legal status in EU countries"

PLIST=		${.CURDIR}/pkg-plist
EXTRA_PATCHES=	${FILESDIR}/extra-patch-gui.c

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk-version
DATAFILES=	capped.png go.png go_.png mask.xpm notdetected.png uncapped.png

.include "${MASTERDIR}/Makefile"
