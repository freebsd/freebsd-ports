# New ports collection makefile for:   fortune-bashorgru
# Date created:        19-04-2007
# Whom:                dindin@dindin.ru
#
# $FreeBSD$
#

PORTNAME=	fortune-bashorgru
PORTVERSION=	20070808
CATEGORIES=	russian
MASTER_SITES=	http://www.dindin.ru/download/

MAINTAINER=	dindin@dindin.ru
COMMENT=	Fortunes from bash.org.ru and freebsd.rusnet.org.ru/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/* ${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/fortune-update.sh ${EXAMPLESDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
