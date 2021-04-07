PORTNAME=	anomaly-mono
DISTVERSION=	g20210310
CATEGORIES=	x11-fonts

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Retrofuturism inspired monospaced programming font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	benbusby
GH_TAGNAME=	9799d01d42b726374fe8733949a84a8ac071e509

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/AnomalyMono-Powerline.otf \
		${FONTSDIR}/AnomalyMono-Regular.otf
do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in Regular Powerline
	${INSTALL_DATA} ${WRKSRC}/AnomalyMono-${i}.otf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
