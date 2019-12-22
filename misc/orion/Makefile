# $FreeBSD$

PORTNAME=	orion
DISTVERSION=	1.6.6-20
DISTVERSIONSUFFIX=	-g127664b
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QML/C++-written desktop client for Twitch.tv

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++14-lang gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	alamminsalo
USE_QT=		core declarative graphicaleffects gui network quickcontrols2 svg widgets buildtools_build
USE_GL=		gl

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/Orion.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svgz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/distfiles/Orion.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${GZIP_CMD} ${GZIP} < ${WRKSRC}/distfiles/${PORTNAME}.svg > ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svgz

.include <bsd.port.mk>
