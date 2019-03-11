# $FreeBSD$

PORTNAME=	proggy_fonts-ttf
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://upperbounds.net/download/
DISTFILES=	ProggyClean.ttf.zip ProggySquare.ttf.zip \
		ProggySmall.ttf.zip ProggyTiny.ttf.zip	\
		ProggyCleanSZ.ttf.zip ProggySquareSZ.ttf.zip \
		ProggyTinySZ.ttf.zip ProggyCleanSZBP.ttf.zip
DIST_SUBDIR=	proggy_fonts-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The perfect monospaced bitmap programming fonts, TTF version

LICENSE=	MIT

USES=		fonts zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
