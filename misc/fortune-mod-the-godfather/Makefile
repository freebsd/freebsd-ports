# New ports collection makefile for:   fortune-mod-the-godfather
# Date created:        11 October 2007
# Whom:                Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-the-godfather
PORTVERSION=	3.0
CATEGORIES=	misc
MASTER_SITES=	http://izb.knu.ac.kr/~bh/fortune/

MAINTAINER=	bh@izb.knu.ac.kr
COMMENT=	Compilation of excuses from the "The Godfather"

NO_BUILD=	yes

SUB_FILES=	pkg-message

STRFILE=	/usr/games/strfile

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/the-godfather ${PREFIX}/share/games/fortune
	@${STRFILE} ${PREFIX}/share/games/fortune/the-godfather
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
