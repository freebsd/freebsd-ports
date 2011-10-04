# New ports collection makefile for:   fortune-bashorgru
# Date created:        19-04-2007
# Whom:                dindin@dindin.ru
#
# $FreeBSD$
#

PORTNAME=	fortune-bashorgru
PORTVERSION=	20080903
CATEGORIES=	russian
MASTER_SITES=	http://limbo.xim.bz/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortunes from bash.org.ru and freebsd.rusnet.org.ru/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/share/games/fortune/ru_RU.UTF-8
	@${MKDIR} ${PREFIX}/share/games/fortune/ru_RU.KOI8-R
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/fortune-bashorgru ${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/fortune-bashorgru.dat ${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/fortune-bashorgru-freebsd ${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/utf-8/fortune-bashorgru-freebsd.dat ${PREFIX}/share/games/fortune/ru_RU.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/fortune-bashorgru ${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/fortune-bashorgru.dat ${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/fortune-bashorgru-freebsd ${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/koi8-r/fortune-bashorgru-freebsd.dat ${PREFIX}/share/games/fortune/ru_RU.KOI8-R/
	${INSTALL_DATA} ${WRKSRC}/fortune-update.py ${EXAMPLESDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
