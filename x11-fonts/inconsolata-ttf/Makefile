PORTNAME=	inconsolata-ttf
DISTVERSION=	3.000
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/Inconsolata/releases/download/v${DISTVERSION}/
DISTNAME=	fonts_ttf
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Monospaced truetype font
WWW=		https://fonts.google.com/specimen/Inconsolata

LICENSE=	OFL11

USES=		fonts

EXTRACT_AFTER_ARGS=	--include fonts/ttf/Inconsolata-Bold.ttf \
			--include fonts/ttf/Inconsolata-Regular.ttf \
			--strip-components 2 \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/Inconsolata-Bold.ttf \
		${FONTSDIR}/Inconsolata-Regular.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
