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

USES=		tar:bzip2
SUB_FILES+=	pkg-message
.if exists(/usr/games/strfile)
_STRFILE=	/usr/games/strfile
.elif exists(/usr/bin/strfile)
_STRFILE=	/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

post-extract:
	${RM} ${WRKSRC}/bible.dat

do-build:
	@cd ${WRKSRC} && ${_STRFILE} -C bible

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/bible* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
