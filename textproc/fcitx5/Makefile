PORTNAME=	fcitx5
DISTVERSION=	5.0.23
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/ \
		https://download.fcitx-im.org/data/:dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SPELL_EN_DICT_TAR}:dict
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/fcitx/${PORTNAME}/commit/
PATCHFILES=	7fb3a5500270877d93b61b11b2a17b9b8f6a506b.patch:-p1

MAINTAINER=	khng@FreeBSD.org
COMMENT=	New implementation of the Fcitx IME framework
WWW=		https://github.com/fcitx/fcitx5

LICENSE=	LGPL21+

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		uthash>=0:devel/uthash
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libjson-c.so:devel/json-c \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xkeyboard-config>=0:x11/xkeyboard-config

# gettext-tools for both build-time hard requirement and Fcitx5 helper shell scripts
USES=		cmake compiler:c++17-lang gettext-runtime \
		gettext-tools:build,run gl gnome kde:5 pkgconfig tar:xz

PLIST_SUB=	VER=${DISTVERSION}

CONFLICTS=	zh-fcitx

OPTIONS_DEFINE=		ENCHANT WAYLAND X11
OPTIONS_DEFAULT=	ENCHANT WAYLAND X11
OPTIONS_SUB=		yes

SUB_FILES=	pkg-message

X11_USES=		xorg
X11_USE=		XORG=xcb,xkbfile
X11_BUILD_DEPENDS=	xcb-imdkit>=1.0.3:x11/xcb-imdkit
X11_LIB_DEPENDS=	libxcb-ewmh.so:x11/xcb-util-wm \
			libxcb-icccm.so:x11/xcb-util-wm \
			libxcb-keysyms.so:x11/xcb-util-keysyms \
			libxcb-util.so:x11/xcb-util
X11_RUN_DEPENDS=	xcb-imdkit>=1.0.3:x11/xcb-imdkit

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
			wayland-scanner:graphics/wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland

ENCHANT_DESC=		Dictionary/spellchecking framework
ENCHANT_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2
ENCHANT_CMAKE_BOOL=	ENABLE_ENCHANT

CMAKE_ON=	FCITX5_DOWNLOAD_DISALLOWED SYSTEM_USE_UTHASH
CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

USE_GL=		egl
USE_GNOME=	cairo gdkpixbuf2 glib20 pango
USE_KDE=	ecm

USE_LDCONFIG=	yes

# These must follow src/modules/spell/dict/CMakeLists.txt
SPELL_EN_DICT_VER=	20121020
SPELL_EN_DICT_TAR=	en_dict-${SPELL_EN_DICT_VER}.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${SPELL_EN_DICT_TAR} ${WRKSRC}/src/modules/spell/

.include <bsd.port.mk>
