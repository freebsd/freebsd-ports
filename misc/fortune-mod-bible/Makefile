# Created by: djp
# $FreeBSD$

PORTNAME=	fortune-mod-bible
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/fortunebible/fortunebible/Genesis
DISTNAME=	bible

MAINTAINER=	doug@polands.org
COMMENT=	King James V Bible in fortune file format

DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_BZIP2=	yes
SUB_FILES+=	pkg-message
_STRFILE=	/usr/games/strfile

do-build:
	@cd ${WRKSRC} && ${_STRFILE} -C bible

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bible* ${STAGEDIR}${PREFIX}/share/games/fortune


.include <bsd.port.mk>
