# New ports collection makefile for:	cvsup
# Version required:	15.4
# Date created:		7 August 1996
# Whom:			asami
#
# $Id: Makefile,v 1.24 1998/04/28 22:25:03 jdp Exp $
#

DISTNAME=	cvsup-15.4
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/CVSup/ \
		ftp://ftp.polstra.com/pub/FreeBSD/CVSup/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-6:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3\\.6\\.:${PORTSDIR}/lang/modula-3-lib

MAN1=		cvsup.1
MAN8=		cvsupd.8

# Support building on systems with or without X11 installed.  The
# modula-3-lib port only supports X11R6 in the standard location,
# so we don't bother using the X11BASE macro.  It's not defined yet
# at this point in the Makefile anyway.
.if !exists(/usr/X11R6/lib/libX11.a)
M3FLAGS+=	-DNOGUI
.endif

# Build options.  Uncomment the desired ones.
# To build the client without GUI support (automatic if X11R6 is not found):
#M3FLAGS+=	-DNOGUI
# To link the programs statically:
#M3FLAGS+=	-DSTATIC
# To link just the Modula-3 libraries statically:
#M3FLAGS+=	-DM3STATIC

MAKE_ENV+=	M3FLAGS="${M3FLAGS}"

.include <bsd.port.mk>
