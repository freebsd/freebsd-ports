# New ports collection makefile for:	gdict
# Date created:			Sun Jul 18 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gdict
PORTVERSION=	0.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.psilord.com/code/gdict/old/

MAINTAINER=	domi@saargate.de

USE_GTK=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdict ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dict ${PREFIX}/bin/cdict

.include <bsd.port.mk>
