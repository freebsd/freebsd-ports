PORTNAME=	ibus
DISTVERSION=	1.5.33
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Input Bus for Unix-like systems
WWW=		https://github.com/ibus/ibus

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/unicode/ucd/NamesList.txt:textproc/UCD \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		bash:shells/bash \
		iso-codes>0:misc/iso-codes \
		evdev-proto>0:devel/evdev-proto
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		iso-codes>0:misc/iso-codes \
		setxkbmap:x11/setxkbmap

USES=		compiler cpe gmake gnome libtool localbase pathfix pkgconfig \
		python shebangfix vala:build xorg
CPE_VENDOR=	ibus_project
USE_GNOME=	glib20 pygobject3
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
USE_XORG=	x11 xfixes xi xtst
SHEBANG_GLOB=	*.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-install-tests \
		--disable-python2 \
		--disable-systemd-services \
		--with-html-dir=${PREFIX}/share/doc \
		--with-ucd-dir=${LOCALBASE}/share/unicode/ucd

INSTALL_TARGET=	install-strip
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/src/tests

OPTIONS_DEFINE=		APPINDICATOR DCONF DOCS EMOJI ENGINE GINTRO GTK2 GTK3 \
			GTK4 NLS TESTS VAPI WAYLAND XIM
OPTIONS_DEFAULT=	APPINDICATOR DCONF EMOJI ENGINE GINTRO GTK3 GTK4 VAPI \
			WAYLAND XIM
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

APPINDICATOR_DESC=	Enable appindicator support
DCONF_DESC=		Use dconf for configuration
EMOJI_DESC=		Install emoji dictionary
ENGINE_DESC=		Install ibus simple engine
GINTRO_DESC=		Install GObject Introspection data
GTK2_DESC=		Install GTK2 input method client
GTK3_DESC=		Install GTK3 input method client
GTK4_DESC=		Install GTK4 input method client
TESTS_DESC=		Build tests
WAYLAND_DESC=		Enable Wayland support
XIM_DESC=		Install XIM server

APPINDICATOR_IMPLIES=		GTK3
APPINDICATOR_LIB_DEPENDS=	libdbusmenu-glib.so:devel/libdbusmenu
APPINDICATOR_CONFIGURE_ENABLE=	appindicator
DCONF_USE=			GNOME=dconf
DCONF_CONFIGURE_ENABLE=		dconf
DCONF_VARS=			GLIB_SCHEMAS=org.freedesktop.ibus.gschema.xml
DOCS_BUILD_DEPENDS=		gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=		gtk-doc-html
EMOJI_BUILD_DEPENDS=		cldr-emoji-annotation>0:misc/cldr-emoji-annotation \
				json-glib>=0:devel/json-glib \
				unicode-emoji>0:misc/unicode-emoji
EMOJI_CONFIGURE_ON=		--with-emoji-annotation-dir=${LOCALBASE}/share/unicode/cldr/common/annotations \
				--with-unicode-emoji-dir=${LOCALBASE}/share/unicode/emoji
EMOJI_CONFIGURE_ENABLE=		emoji-dict
ENGINE_CONFIGURE_ENABLE=	engine
GINTRO_USE=			GNOME=introspection:build
GINTRO_CONFIGURE_ENABLE=	introspection
GTK2_LIB_DEPENDS=		libdbus-1.so:devel/dbus
GTK2_USE=			GNOME=cairo,gtk20
GTK2_CONFIGURE_ENABLE=		gtk2
GTK3_IMPLIES=			GINTRO
GTK3_LIB_DEPENDS=		libdbus-1.so:devel/dbus \
				libnotify.so:devel/libnotify
GTK3_USE=			GNOME=cairo,gtk30,pango
GTK3_CONFIGURE_ENABLE=		gtk3 libnotify
GTK4_IMPLIES=			GINTRO
GTK4_LIB_DEPENDS=		libdbus-1.so:devel/dbus \
				libgraphene-1.0.so:graphics/graphene \
				libvulkan.so:graphics/vulkan-loader
GTK4_USE=			GNOME=cairo,gtk40,gdkpixbuf
GTK4_CONFIGURE_ENABLE=		gtk4
NLS_USES=			gettext
NLS_USES_OFF=			gettext-tools
NLS_CONFIGURE_ENABLE=		nls
TESTS_IMPLIES=			GTK3 GTK4 XIM
TESTS_CONFIGURE_ENABLE=		tests
VAPI_IMPLIES=			GINTRO
VAPI_CONFIGURE_ENABLE=		vala
WAYLAND_BUILD_DEPENDS=		wayland>1.14:graphics/wayland \
				wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_CONFIGURE_ENABLE=	wayland
XIM_IMPLIES=			GTK3
XIM_CONFIGURE_ENABLE=		xim

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MENGINE} || ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MDCONF}
PLIST_SUB+=	COMPDIR=""
.else
PLIST_SUB+=	COMPDIR="@comment "
.endif

post-configure:
	# Clean pre-generated source code, which may not match the options selected.
	${MAKE} -C ${WRKSRC}/ui/gtk3 maintainer-clean-generic
	${RM} ${WRKSRC}/tools/main.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${PATCHDIR}/ibus.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.post.mk>
