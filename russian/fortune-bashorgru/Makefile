# Created by: dindin@dindin.ru
# $FreeBSD$

PORTNAME=	fortune-bashorgru
PORTVERSION=	20080903
PORTREVISION=	1
CATEGORIES=	russian
MASTER_SITES=	http://limbo.xim.bz/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortunes from bash.org.ru and freebsd.rusnet.org.ru/bash

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/ru_RU.UTF-8
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/ru_RU.KOI8-R
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/* ${STAGEDIR}${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/* ${STAGEDIR}${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/fortune-update.py ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
