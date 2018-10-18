# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	emojione-color-font-ttf
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/eosrei/emojione-color-font/releases/download/v${PORTVERSION}/
DISTNAME=	EmojiOneColor-SVGinOT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color emoji font using EmojiOne Unicode 9.0

LICENSE=	CC-BY-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-4.0+=	${WRKSRC}/LICENSE-CC-BY.txt
LICENSE_FILE_MIT+=		${WRKSRC}/LICENSE-MIT.txt

DEPRECATED=	EOL upstream, please use x11-fonts/twemoji-color-font-ttf instead
EXPIRATION_DATE=	2018-11-18

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${FONTSDIR}/EmojiOneColor-SVGinOT.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
