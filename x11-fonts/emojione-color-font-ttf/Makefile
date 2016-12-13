# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	emojione-color-font-ttf
PORTVERSION=	1.3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://github.com/eosrei/emojione-color-font/releases/download/v${PORTVERSION}/
DISTNAME=	EmojiOneColor-SVGinOT-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Color emoji font using EmojiOne Unicode 9.0

LICENSE=	CC-BY-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-4.0+=	${WRKSRC}/LICENSE-CC-BY.txt
LICENSE_FILE_MIT+=		${WRKSRC}/LICENSE-MIT.txt

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${FONTSDIR}/EmojiOneColor-SVGinOT.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
