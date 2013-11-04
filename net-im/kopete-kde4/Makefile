# $FreeBSD$

PORTNAME=	kopete
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdenetwork-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn \
		qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr3 \
		gadu.3:${PORTSDIR}/polish/libgadu \
		ortp.8:${PORTSDIR}/net/linphone-base \
		mediastreamer.0:${PORTSDIR}/net/linphone-base \
		speex.1:${PORTSDIR}/audio/speex \
		expat.6:${PORTSDIR}/textproc/expat2 \
		meanwhile.1:${PORTSDIR}/net-im/meanwhile \
		v4l2.0:${PORTSDIR}/multimedia/libv4l \
		jasper.4:${PORTSDIR}/graphics/jasper \
		gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.11:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/lib/mediastreamer/plugins/libmsilbc.so:${PORTSDIR}/audio/msilbc
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl \
		${LOCALBASE}/lib/mediastreamer/plugins/libmsilbc.so:${PORTSDIR}/audio/msilbc

LATEST_LINK=	${PORTNAME}4
DISTINFO_FILE=	${.CURDIR}/../../net/kdenetwork4/distinfo

CONFLICTS_INSTALL=	kdenetwork-4.[1-8].*

USES=		cmake:outsource
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs \
		automoc4 qimageblitz
USE_OPENSSL=	yes
USE_QT4=	corelib gui network qt3support sql xml \
		moc_build qmake_build rcc_build uic_build uic3_build
USE_SQLITE=	yes
USE_XORG=	x11 xdamage xext xscrnsaver xtst
USE_XZ=		yes
USE_LDCONFIG=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}

USE_WEBPLUGINS=	native
WEBPLUGINS_NAME=	# empty
WEBPLUGINS_FILES=	skypebuttons.so

# Explicitly disable ALSA, as it's not used (Jabber Jingle support is
# not built).
CMAKE_ARGS+=	-DWITH_Alsa:BOOL=OFF

# Route Mozilla plugin by standard path.
CMAKE_ARGS+=	-DMOZPLUGIN_INSTALL_DIR:PATH="${WEBPLUGINS_DIR}"

# Forcefully disable net-im/libmsn which was deprecated on 2013-07-27.
CMAKE_ARGS+=	-DHAVE_LIBMSN:BOOL=OFF

# Fix build with fresh multimedia/v4l_compat installed.
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES=1

OPTIONS_DEFINE=	XMMS
XMMS_DESC=	XMMS Kopete nowlistening plugin

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${PORT_OPTIONS:MXMMS}
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=ON
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.else
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF
.endif

.include <bsd.port.mk>
