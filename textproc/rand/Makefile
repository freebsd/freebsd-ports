# New ports collection makefile for:	rand
# Date created:			Mon Jul 26 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	rand
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://math.smsu.edu/~erik/files/

MAINTAINER=	domi@saargate.de
COMMENT=	Utility to display files or streams in random order

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		rand.1
PLIST_FILES=	bin/rand

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rand.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
