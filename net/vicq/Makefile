# New ports collection makefile for:	vicq
# Date created:				06 December 2001
# Whom:					Kevin Lo<kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vicq
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq/

MAINTAINER=	kevlo@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include <bsd.port.mk>
