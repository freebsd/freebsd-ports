PORTNAME=	retroshare
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	17
CATEGORIES=	net-p2p

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	428b331d8efe.patch:-p1

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform
WWW=		https://retroshare.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher \
		libgnome-keyring.so:security/libgnome-keyring \
		libgpgme.so:security/gpgme \
		libcurl.so:ftp/curl \
		libminiupnpc.so:net/miniupnpc

USES=		compiler:features desktop-file-utils dos2unix \
		gl gnome pkgconfig qmake qt:5 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	RetroShare
GH_PROJECT=	RetroShare
RS_REVISION=	0e6d27a
USE_GNOME=	libxml2 libxslt
USE_GL=		gl
USE_QT=		core gui multimedia printsupport network widgets xml \
		buildtools:build uitools:build
DOS2UNIX_FILES=	retroshare-nogui/src/retroshare-nogui.pro \
		retroshare-gui/src/gui/elastic/node.cpp

OPTIONS_DEFINE=	VOIP WEBUI
OPTIONS_SUB=	yes

VOIP_DESC=		Build with VoIP plugin (requires OpenCV)
VOIP_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libopencv_highgui.so:graphics/opencv \
			libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
VOIP_BROKEN=	gui/QVideoDevice.cpp:1:10: fatal error: 'opencv/cv.h' file not found

WEBUI_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBUI_QMAKE_OFF=	CONFIG+=no_libresapihttpserver
WEBUI_BROKEN=	api/ApiServerMHD.cpp:376:5: error: no matching function for call to 'MHD_get_connection_values'

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare.pri
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsaccounts.cc
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/retroshare-gui.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/data/retroshare.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/data/retroshare.desktop
	@${REINPLACE_CMD} -e 's|RS_REVISION_NUMBER.*|RS_REVISION_NUMBER   0x${RS_REVISION}|' \
		${WRKSRC}/libretroshare/src/retroshare/rsversion.h

post-patch-VOIP-off:
# VoIP plugin does not build against modern `graphics/opencv' port
	@${REINPLACE_CMD} -e '/VOIP/d' ${WRKSRC}/plugins/plugins.pro

.include <bsd.port.post.mk>
