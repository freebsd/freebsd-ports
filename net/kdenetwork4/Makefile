# New ports collection Makefile for:	kdepim
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdenetwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	net kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network applications

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
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
		telepathy-qt4.0:${PORTSDIR}/net-im/telepathy-qt4 \
		meanwhile.1:${PORTSDIR}/net-im/meanwhile \
		speex.1:${PORTSDIR}/audio/speex \
		v4l2.0:${PORTSDIR}/multimedia/libv4l \
		kwebkit.1:${PORTSDIR}/www/kwebkitpart \
		ktorrent.2:${PORTSDIR}/net-p2p/libktorrent
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

# Route mozilla plugin by standard path
CMAKE_ARGS+=	-DMOZPLUGIN_INSTALL_DIR=${PREFIX}/lib/browser_plugins

# Fix build with fresh multimedia/v4l_compat installed
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
