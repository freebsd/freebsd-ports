# New ports collection makefile for:   wmCalClock
# Version required:    1.22
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	wmCalClock-1.22
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	ftp://leadbelly.lanl.gov/pub/mgh/ \
		ftp://ftp.ukrnet.net/pub/Unix/WindowMaker/src/

MAINTAINER=	kris@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm/

WRKSRC=		${WRKDIR}/${DISTNAME}/wmCalClock

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

ALL_TARGET=	clean all

MAN1=		wmCalClock.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/share/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include <bsd.port.mk>
