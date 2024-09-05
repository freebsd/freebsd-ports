PORTNAME=	rssguard
PORTVERSION=	4.7.3		# don't forget to update APP_REVISION below
PORTREVISION=	1
CATEGORIES=	net www

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b0e2b4bb5d8fffe7ef15.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple (yet powerful) Qt-based feed reader
WWW=		https://github.com/martinrotter/rssguard

LICENSE=	GPLv3+

USES=		cmake qt:5 sqlite
USE_QT=		buildtools:build linguisttools:build qmake:build \
		concurrent core dbus declarative gui multimedia \
		network sql widgets xml sql-sqlite3:run
USE_GITHUB=	yes
GH_ACCOUNT=	martinrotter

CMAKE_ARGS=	-DAPP_REVISION:STRING=a4e2048
CMAKE_ON=	NO_UPDATE_CHECK ENABLE_COMPRESSED_SITEMAP
CMAKE_OFF=	BUILD_WITH_QT6 REVISION_FROM_GIT

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_RADIO=	MULTIMEDIA
OPTIONS_DEFAULT=	LIBMPV
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

MULTIMEDIA_DESC=	Built-in media player
OPTIONS_RADIO_MULTIMEDIA=	LIBMPV QTFFMPEG

LIBMPV_DESC=		Play basically every thinkable audio/video
LIBMPV_LIB_DEPENDS=	libmpv.so:multimedia/mpv
LIBMPV_CMAKE_OFF=	-DENABLE_MEDIAPLAYER_LIBMPV:BOOL=OFF

QTFFMPEG_DESC=	QtMultimedia/FFmpeg-based (slightly lighter)
QTFFMPEG_CMAKE_ON=	-DENABLE_MEDIAPLAYER_QTMULTIMEDIA:BOOL=ON

WEBENGINE_DESC=	Use QtWebEngine module for internal web browser
WEBENGINE_USE=	QT=location,printsupport,webchannel,webengine
WEBENGINE_CMAKE_OFF=	-DNO_LITE:BOOL=OFF
WEBENGINE_PLIST_SUB=		PROGNAME=${PORTNAME}
WEBENGINE_PLIST_SUB_OFF=	PROGNAME=${PORTNAME}lite

.include <bsd.port.mk>
