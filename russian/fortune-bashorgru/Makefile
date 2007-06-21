# New ports collection makefile for:   fortune-bashorgru
# Date created:        19-04-2007
# Whom:                dindin@dindin.ru
#
# $FreeBSD$
#

PORTNAME=	fortune-bashorgru
PORTVERSION=	20070621
CATEGORIES=	russian
MASTER_SITES=	http://www.dindin.ru/download/

MAINTAINER=	dindin@dindin.ru
COMMENT=	Fortunes from bash.org.ru

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}/
	@${MKDIR} ${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/* ${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/fortune-update.sh ${PREFIX}/share/examples/${PORTNAME}/

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/rus/${PORTNAME}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Example script to keep your fortune up to date placed in"
	@${ECHO_MSG} "${PREFIX}/share/examples/${PORTNAME}/"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
