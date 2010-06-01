# New ports collection Makefile for:	kdepim
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	slp.1:${PORTSDIR}/net/openslp \
		idn.16:${PORTSDIR}/dns/libidn \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qca.2:${PORTSDIR}/devel/qca \
		otr.4:${PORTSDIR}/security/libotr \
		vncserver.0:${PORTSDIR}/net/libvncserver \
		msn.0:${PORTSDIR}/net-im/libmsn \
		gadu:${PORTSDIR}/polish/libgadu \
		gmp.10:${PORTSDIR}/math/gmp \
		ortp.5:${PORTSDIR}/net/ortp \
		telepathy-qt4.4:${PORTSDIR}/net-im/telepathy-qt4 \
		meanwhile.1:${PORTSDIR}/net-im/meanwhile \
		speex.1:${PORTSDIR}/audio/speex \
		v4l2.0:${PORTSDIR}/multimedia/libv4l
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4 kdebase workspace
KDE4_BUILDENV=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
QT_COMPONENTS=	corelib opengl dbus qt3support gui network xml porting_build \
		qmake_build moc_build rcc_build uic_build uic3_build
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

# Explicitly disable alsa, see for details:
# http://mail.kde.org/pipermail/kde-freebsd/2010-March/008015.html
CMAKE_ARGS+=	-DWITH_Alsa:BOOL=OFF

# Embedded btcore support already disconnected from the build and outdated
CMAKE_ARGS+=	-DENABLE_EMBEDDED_TORRENT_SUPPORT=FALSE

# Route mozilla plugin by standard path
CMAKE_ARGS+=	-DMOZPLUGIN_INSTALL_DIR=${PREFIX}/lib/browser_plugins

# Fix build with fresh multimedia/v4l_compat installed
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES=1

OPTIONS=	BTCORE "Enable Bittorrent support in KGet" off \
		WEBKIT "Enable KWebKit support in KGet" off \
		XMMS "Enable XMMS Kopete nowlistening plugin" off

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

.if defined(WITH_BTCORE)
LIB_DEPENDS+=	btcore.12:${PORTSDIR}/net-p2p/ktorrent
PLIST_SUB+=	BTCORE=""
.else
PLIST_SUB+=	BTCORE="@comment "
.endif

.ifdef(WITH_WEBKIT)
LIB_DEPENDS+=	kwebkit.1:${PORTSDIR}/www/kwebkitpart
CMAKE_ARGS+=	-DWITH_KWebKitPart:BOOL=ON
PLIST_SUB+=	WEBKIT=""
.else
CMAKE_ARGS+=	-DWITH_KWebKitPart:BOOL=OFF
PLIST_SUB+=	WEBKIT="@comment "
.endif

pre-configure:
.if !defined(WITH_BTCORE)
	${REINPLACE_CMD} -e '/bittorrent/ d' \
		${WRKSRC}/kget/transfer-plugins/CMakeLists.txt
.endif

.include <bsd.port.mk>
