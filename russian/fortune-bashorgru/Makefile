# Created by: dindin@dindin.ru
# $FreeBSD$

PORTNAME=	fortune-bashorgru
PORTVERSION=	20080903
CATEGORIES=	russian
MASTER_SITES=	http://limbo.xim.bz/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortunes from bash.org.ru and freebsd.rusnet.org.ru/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/share/games/fortune/ru_RU.UTF-8
	@${MKDIR} ${PREFIX}/share/games/fortune/ru_RU.KOI8-R
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/* ${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/* ${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/fortune-update.py ${EXAMPLESDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
