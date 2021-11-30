# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5
DISTVERSION=	5.0.10
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/data/:dict
DISTFILES=	${SPELL_EN_DICT_TAR}:dict
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	New implementation of the Fcitx IME framework

LICENSE=	LGPL21+

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		uthash>=0:devel/uthash
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid \
		libfmt.so:devel/libfmt \
		libxkbcommon.so:x11/libxkbcommon \
		libexpat.so:textproc/expat2 \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xkeyboard-config>=0:x11/xkeyboard-config

# gettext-tools for both build-time hard requirement and Fcitx5 helper shell scripts
USES=		cmake compiler:c++17-lang gettext-runtime gettext-tools:build,run gl gnome kde:5 pkgconfig

PLIST_SUB=	VER=${PORTVERSION}

CONFLICTS=	zh-fcitx

OPTIONS_DEFINE=		X11 WAYLAND ENCHANT
OPTIONS_DEFAULT=	X11 WAYLAND ENCHANT
OPTIONS_SUB=		yes

SUB_FILES=	pkg-message

X11_USES=	xorg
X11_USE=	xorg=xcb,xkbfile
X11_LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
			libxcb-keysyms.so:x11/xcb-util-keysyms \
			libxcb-ewmh.so:x11/xcb-util-wm \
			libxcb-icccm.so:x11/xcb-util-wm \
			libxcb-imdkit.so:x11/xcb-imdkit

WAYLAND_BUILD_DEPENDS=	wayland-scanner:graphics/wayland \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland

ENCHANT_DESC=		Dictionary/spellchecking framework
ENCHANT_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2
ENCHANT_CMAKE_BOOL=	ENABLE_ENCHANT

CMAKE_ON=	SYSTEM_USE_UTHASH FCITX5_DOWNLOAD_DISALLOWED
CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

USE_GL=		egl
USE_GNOME=	cairo glib20 gdkpixbuf2 pango
USE_KDE=	ecm

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

# These must follow src/modules/spell/dict/CMakeLists.txt
SPELL_EN_DICT_VER=	20121020
SPELL_EN_DICT_TAR=	en_dict-${SPELL_EN_DICT_VER}.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${SPELL_EN_DICT_TAR} ${WRKSRC}/src/modules/spell/dict

.include <bsd.port.mk>
