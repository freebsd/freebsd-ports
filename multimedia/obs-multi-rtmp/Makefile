PORTNAME=	obs-multi-rtmp
DISTVERSION=	0.7.3.1
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Multistream plugin for OBS Studio
WWW=		https://github.com/sorayuki/obs-multi-rtmp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	sorayuki
USE_GL=		opengl
USE_QT=		base

CMAKE_ON=	ENABLE_QT
CMAKE_OFF=	CMAKE_COMPILE_WARNING_AS_ERROR

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/locale
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL_DATA} \
		${WRKSRC}/data/locale/*.ini \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/locale

.include <bsd.port.mk>
