# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus
PORTVERSION=	1.5.24
CATEGORIES=	textproc

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Input Bus for Linux / Unix OS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:devel/py-dbus@${PY_FLAVOR} \
		${LOCALBASE}/share/unicode/ucd/NamesList.txt:textproc/UCD \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		gtkdocize:textproc/gtk-doc \
		bash:shells/bash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:devel/py-dbus@${PY_FLAVOR} \
		${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes \
		setxkbmap:x11/setxkbmap

USES=		autoreconf compiler cpe gmake gnome libtool localbase \
		pathfix pkgconfig python:3.5+ shebangfix
CPE_VENDOR=	ibus_project
USE_GITHUB=	yes
USE_GNOME=	glib20 intltool librsvg2 pygobject3
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist


SHEBANG_GLOB=	*.sh


GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc	\
		--with-ucd-dir=${LOCALBASE}/share/unicode/ucd \
		--disable-python2 --disable-python-library \
		--disable-gtk4

MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ENGINE VALA GTK2 GTK3 GINTRO XIM EMOJI DOCS NLS WAYLAND
OPTIONS_DEFAULT=	GTK2 GTK3 VALA GINTRO DCONF XIM ENGINE EMOJI
OPTIONS_RADIO=	CONFIG
OPTIONS_RADIO_CONFIG=	GCONF DCONF
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=	yes

DCONF_DESC=	Use dconf for configuration
EMOJI_DESC=	Install emoji dictionary
ENGINE_DESC=	Install ibus simple engine
GCONF_DESC=	Use GConf for configuration
GINTRO_DESC=	Install GObject Introspection data
GTK2_DESC=	Install GTK2 client
GTK3_DESC=	Install GTK3 client and panel
VALA_DESC=	Install vala binding
WAYLAND_DESC=	Enable Wayland support
XIM_DESC=	Install XIM server

DCONF_USE=		GNOME=dconf
DCONF_CONFIGURE_ENABLE=	dconf
DCONF_VARS=		GLIB_SCHEMAS=org.freedesktop.ibus.gschema.xml
DOCS_CONFIGURE_ENABLE=	gtk-doc-html
EMOJI_BUILD_DEPENDS=	json-glib>=0:devel/json-glib \
			unicode-emoji>0:misc/unicode-emoji \
			cldr-emoji-annotation>0:misc/cldr-emoji-annotation
EMOJI_CONFIGURE_ON=	--with-unicode-emoji-dir=${LOCALBASE}/share/unicode/emoji \
			--with-emoji-annotation-dir=${LOCALBASE}/share/unicode/cldr/common/annotations
EMOJI_CONFIGURE_ENABLE=	emoji-dict
ENGINE_CONFIGURE_ENABLE=	engine
GCONF_USE=		GNOME=gconf2
GCONF_CONFIGURE_ENABLE=	gconf
GCONF_VARS=		GCONF_SCHEMAS=ibus.schemas
GINTRO_BUILD_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_RUN_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_CONFIGURE_ENABLE=	introspection
GTK2_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USE=		GNOME=cairo,gtk20
GTK2_CONFIGURE_ENABLE=	gtk2
GTK3_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libnotify.so:devel/libnotify
GTK3_USES=		xorg
GTK3_USE=		GNOME=cairo,gtk30 XORG=x11,xi
GTK3_CONFIGURE_ENABLE=	gtk3 libnotify
GTK3_LIBS=		-lX11
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls
VALA_IMPLIES=		GINTRO
VALA_BUILD_DEPENDS=	vala>=0.20:lang/vala
VALA_CONFIGURE_ENABLE=	vala
WAYLAND_BUILD_DEPENDS=	wayland>1.14:graphics/wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_CONFIGURE_ENABLE=	wayland
XIM_CONFIGURE_ENABLE=	xim

EMOJIONE_TAG=		ba845a7e24aac26cf3cf22abc19bea215d94fbf3 # 2.2.7

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MENGINE} || ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MGCONF} || ${PORT_OPTIONS:MDCONF}
PLIST_SUB+=	COMPDIR=""
.else
PLIST_SUB+=	COMPDIR="@comment "
.endif

pre-configure:
	cd ${CONFIGURE_WRKSRC} && gtkdocize --copy --flavour no-tmpl

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${PATCHDIR}/ibus.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart

do-test:
	${MAKE} -C ${WRKSRC}/src/tests check

.include <bsd.port.post.mk>
