# New ports collection makefile for:   pspresent
# Date created:        25 Jul 2007
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	pspresent
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.cse.unsw.edu.au/~matthewc/pspresent/

MAINTAINER=	timbob@bigpond.com
COMMENT=	Full-screen slide shows of postscript files

USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	x11 xext xinerama
ALL_TARGET=	pspresent
PLIST_FILES=	bin/pspresent

MAN1=		pspresent.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pspresent ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/pspresent.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
