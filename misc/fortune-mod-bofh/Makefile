# New ports collection makefile for:   fortune-mod-bofh
# Date created:        3/3/2004
# Whom:                Yonatan@Xpert.com
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-bofh
PORTVERSION=	2.0
CATEGORIES=	misc
MASTER_SITES=	http://www.void.irq.org/
DISTNAME=	bofh-fortune-mod${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Compilation of excuses from the "Bastard Operator From Hell"

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${CAT} pkg-message | ${SED} 's|PREFIX|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bofh ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bofh.dat ${PREFIX}/share/games/fortune
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
