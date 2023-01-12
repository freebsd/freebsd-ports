PORTNAME=	obs-scrab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Screenshot plugin
WWW=		https://github.com/univrsal/scrab

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		installs into the build directory, see https://github.com/univrsal/scrab/issues/7

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake gl localbase:ldflags qt:6

USE_QT=		base tools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	univrsal
GH_PROJECT=	scrab

CMAKE_ARGS=	-DOS_POSIX:BOOL=TRUE -DLINUX_PORTABLE:BOOL=FALSE
CXXFLAGS+=	-I${LOCALBASE}/include/obs

PLIST_FILES=	lib/obs-plugins/scrab.so \
		share/obs/obs-plugins/scrab/locale/en-US.ini

do-install: # workaround for https://github.com/univrsal/scrab/issues/7
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/scrab/locale
	${INSTALL} \
		${BUILD_WRKSRC}/scrab.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL} \
		${WRKSRC}/data/locale/en-US.ini \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/scrab/locale

.include <bsd.port.mk>
