# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

LIB_DEPENDS=	slp.1:${PORTSDIR}/net/openslp \
		idn.17:${PORTSDIR}/dns/libidn \
		qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr3 \
		vncserver.0:${PORTSDIR}/net/libvncserver \
		msn.0:${PORTSDIR}/net-im/libmsn \
		gadu.3:${PORTSDIR}/polish/libgadu \
		ortp.8:${PORTSDIR}/net/linphone-base \
		mediastreamer.0:${PORTSDIR}/net/linphone-base \
		speex.1:${PORTSDIR}/audio/speex \
		expat.6:${PORTSDIR}/textproc/expat2 \
		meanwhile.1:${PORTSDIR}/net-im/meanwhile \
		v4l2.0:${PORTSDIR}/multimedia/libv4l \
		ktorrent:${PORTSDIR}/net-p2p/libktorrent \
		jasper.4:${PORTSDIR}/graphics/jasper \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		gif.5:${PORTSDIR}/graphics/giflib \
		mms.0:${PORTSDIR}/net/libmms \
		jpeg.11:${PORTSDIR}/graphics/jpeg

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat

RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_GNOME=	glib20 libxml2 libxslt
USE_KDE4=	kdehier kdelibs kdeprefix libkonq pimlibs workspace \
		automoc4 ontologies qimageblitz soprano strigi
KDE4_BUILDENV=	yes
USE_OPENSSL=	yes

# Should probably be build-only, but JIC
USE_PKGCONFIG=	both

USE_QT4=	dbus gui network qt3support sql xml \
		moc_build qmake_build rcc_build uic_build uic3_build
USE_SQLITE=	yes
USE_XORG=	x11 xdamage xext xscrnsaver xtst
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

# Explicitly disable ALSA, as it's not used (Jabber Jingle support is
# not built).
CMAKE_ARGS+=	-DWITH_Alsa:BOOL=OFF

# Route Mozilla plugin by standard path.
CMAKE_ARGS+=	-DMOZPLUGIN_INSTALL_DIR=${PREFIX}/lib/browser_plugins

# Fix build with fresh multimedia/v4l_compat installed.
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES=1

OPTIONS=	XMMS "Enable XMMS Kopete nowlistening plugin" off

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 800074
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=OFF
PLIST_SUB+=	KPPP="@comment "
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-CMakeLists.txt
CMAKE_ARGS+=	-DBUILD_kppp:BOOL=ON
PLIST_SUB+=	KPPP=""
.endif

.if defined(WITH_XMMS)
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=ON
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.else
CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF
.endif

.include <bsd.port.mk>
