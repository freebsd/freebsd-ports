# $FreeBSD$

PORTNAME=	anomaly-mono
DISTVERSION=	g20200110
CATEGORIES=	x11-fonts

MAINTAINER=	vulcan@wired.sh
COMMENT=	Retrofuturism inspired monospaced programming font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	benbusby
GH_TAGNAME=	c97c17282e8d1b244a9571c6eb392aac99ddd76e

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/AnomalyMono.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/AnomalyMono.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
