# New ports collection makefile for:   fortune-mod-bible
# Date created:        3/30/2004
# Whom:                djp
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-bible
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fortunebible
DISTNAME=	bible

MAINTAINER=	doug@polands.org
COMMENT=	King James V Bible in fortune file format

DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_BZIP2=	yes

do-build:
	@${CAT} ${FILESDIR}/pkg-message.in | ${SED} 's#PREFIX#${PREFIX}#' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bible* ${PREFIX}/share/games/fortune

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
