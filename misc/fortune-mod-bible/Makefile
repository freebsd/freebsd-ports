# Created by: djp
# $FreeBSD$

PORTNAME=	fortune-mod-bible
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/fortunebible/fortunebible/Genesis
DISTNAME=	bible
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	doug@polands.org
COMMENT=	King James V Bible in fortune file format

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile

NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USES=		tar:bzip2
SUB_FILES+=	pkg-message
_STRFILE=	${LOCALBASE}/bin/fortune_strfile

post-extract:
	${RM} ${WRKSRC}/bible.dat

do-build:
	(cd ${WRKSRC} && ${_STRFILE} -C bible)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/bible* \
		${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
