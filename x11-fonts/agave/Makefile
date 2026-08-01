PORTNAME=	agave
DISTVERSION=	38
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	TrueType monospaced font designed for X environments
WWW=		https://b.agaric.net/page/agave

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe fonts
CPE_VENDOR=	anomali

USE_GITHUB=	yes
GH_ACCOUNT=	blobject

NO_ARCH=	yes
NO_BUILD=	yes

EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/LICENSE \
			--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/dist/*.ttf \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/dist/*-slashed.ttf \
			--no-same-owner --no-same-permissions

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
