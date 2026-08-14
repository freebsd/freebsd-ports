PORTNAME=	anomaly-mono
DISTVERSION=	g20210310
CATEGORIES=	x11-fonts

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Retrofuturism inspired monospaced programming font
WWW=		https://github.com/benbusby/anomaly-mono

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	benbusby
GH_TAGNAME=	9799d01d42b726374fe8733949a84a8ac071e509

EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/LICENSE \
			--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/*.otf \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/AnomalyMono-Powerline.otf \
		${FONTSDIR}/AnomalyMono-Regular.otf
do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
