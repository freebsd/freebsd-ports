# $FreeBSD$

PORTNAME=	kopete
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libqca.so:${PORTSDIR}/devel/qca \
		libotr.so.5:${PORTSDIR}/security/libotr \
		libgadu.so:${PORTSDIR}/polish/libgadu \
		libortp.so:${PORTSDIR}/net/ortp \
		libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libspeex.so:${PORTSDIR}/audio/speex \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libmeanwhile.so:${PORTSDIR}/net-im/meanwhile \
		libv4l2.so:${PORTSDIR}/multimedia/libv4l \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjsoncpp.so:${PORTSDIR}/devel/jsoncpp
BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/lib/mediastreamer/plugins/libmsilbc.so:${PORTSDIR}/audio/msilbc
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl \
		${LOCALBASE}/lib/mediastreamer/plugins/libmsilbc.so:${PORTSDIR}/audio/msilbc

USES=		cmake:outsource pkgconfig shebangfix tar:xz webplugin:native
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs \
		automoc4 qimageblitz
USE_OPENSSL=	yes
USE_QT4=	corelib gui network qt3support sql xml \
		moc_build qmake_build rcc_build uic_build uic3_build
USE_SQLITE=	yes
USE_XORG=	x11 xdamage xext xscrnsaver xtst
USE_LDCONFIG=	yes

SHEBANG_FILES=	${WRKSRC}/protocols/winpopup/winpopup-install \
		${WRKSRC}/protocols/winpopup/winpopup-send

WEBPLUGIN_NAME=	# empty
WEBPLUGIN_FILES=	skypebuttons.so

# Explicitly disable ALSA, as it's not used (Jabber Jingle support is
# not built).
CMAKE_ARGS+=	-DWITH_Alsa:BOOL=OFF

# Route Mozilla plugin by standard path.
CMAKE_ARGS+=	-DMOZPLUGIN_INSTALL_DIR:PATH="${WEBPLUGIN_DIR}"

# Forcefully disable net-im/libmsn which was deprecated on 2013-07-27.
CMAKE_ARGS+=	-DHAVE_LIBMSN:BOOL=OFF

# Fix build with fresh multimedia/v4l_compat installed.
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES=1

OPTIONS_DEFINE=	XMMS
XMMS_DESC=	XMMS Kopete nowlistening plugin
XMMS_LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
XMMS_CMAKE_ON=	-DWITH_Xmms:BOOL=ON
XMMS_CMAKE_OFF=	-DWITH_Xmms:BOOL=OFF

post-patch:
	${REINPLACE_CMD} 's,-std=gnu90,-std=gnu89,' \
		${WRKSRC}/protocols/jabber/libiris/CMakeLists.txt

.include <bsd.port.mk>
