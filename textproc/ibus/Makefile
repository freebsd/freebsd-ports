# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus
DISTVERSION=	1.5.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/:DEFAULT
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:DEFAULT
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Input Bus for Linux / Unix OS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:devel/py-dbus@${PY_FLAVOR} \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:devel/py-notify@${PY_FLAVOR} \
		${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes \
		setxkbmap:x11/setxkbmap

USES=		compiler cpe gmake libtool localbase pathfix pkgconfig python:2.7
USE_GNOME=	glib20 intltool librsvg2 pygobject3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
OPTIONS_SUB=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-tests --with-html-dir=${PREFIX}/share/doc

OPTIONS_DEFINE=	NLS GTK2 GTK3 VALA GINTRO PYTHON_LIB DOCS XIM ENGINE EMOJI
OPTIONS_RADIO=	CONFIG
OPTIONS_RADIO_CONFIG=	GCONF DCONF
OPTIONS_DEFAULT=	GTK2 GTK3 VALA GINTRO PYTHON_LIB DCONF XIM ENGINE EMOJI

GTK2_DESC=	Install GTK2 client
GTK3_DESC=	Install GTK3 client and panel
VALA_DESC=	Install vala binding
GINTRO_DESC=	Install GObject Introspection data
PYTHON_LIB_DESC=	Install ibus Python libraries
GCONF_DESC=	Use GConf for configuration
DCONF_DESC=	Use dconf for configuration
XIM_DESC=	Install XIM server
ENGINE_DESC=	Install ibus simple engine
EMOJI_DESC=	Install emoji dictionary
CPE_VENDOR=	ibus_project

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

GTK2_USE=		GNOME=cairo,gtk20
GTK2_CONFIGURE_ENABLE=	gtk2
GTK2_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2

GTK3_USE=		GNOME=cairo,gtk30 XORG=x11,xi
GTK3_CONFIGURE_ENABLE=	gtk3 libnotify
GTK3_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libnotify.so:devel/libnotify
GTK3_LIBS=		-lX11

VALA_BUILD_DEPENDS=	vala>=0.20:lang/vala
VALA_CONFIGURE_ENABLE=	vala
VALA_IMPLIES=		GINTRO

GINTRO_BUILD_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_RUN_DEPENDS=	gobject-introspection>=0.6.8:devel/gobject-introspection
GINTRO_CONFIGURE_ENABLE=	introspection

PYTHON_LIB_USE=			GNOME=pygtk2
PYTHON_LIB_CONFIGURE_ENABLE=	python-library

GCONF_USE=		GNOME=gconf2
GCONF_CONFIGURE_ENABLE=	gconf
GCONF_VARS=		GCONF_SCHEMAS=ibus.schemas

DCONF_USE=		GNOME=dconf,gconf2
DCONF_CONFIGURE_ENABLE=	dconf
DCONF_VARS=		GLIB_SCHEMAS=org.freedesktop.ibus.gschema.xml

DOCS_CONFIGURE_ENABLE=	gtk-doc-html

XIM_CONFIGURE_ENABLE=	xim

ENGINE_CONFIGURE_ENABLE=	engine

EMOJIONE_TAG=		ba845a7e24aac26cf3cf22abc19bea215d94fbf3 # 2.2.7
EMOJI_CONFIGURE_ON=	--with-unicode-emoji-dir=${LOCALBASE}/share/unicode/emoji \
			--with-emoji-annotation-dir=${LOCALBASE}/share/unicode/cldr/common/annotations
EMOJI_CONFIGURE_ENABLE=	emoji-dict
EMOJI_BUILD_DEPENDS=	json-glib>=0:devel/json-glib \
			unicode-emoji>0:misc/unicode-emoji \
			cldr-emoji-annotation>0:misc/cldr-emoji-annotation

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MENGINE} || ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MGCONF} || ${PORT_OPTIONS:MDCONF}
PLIST_SUB+=	COMPDIR=""
.else
PLIST_SUB+=	COMPDIR="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${PATCHDIR}/ibus.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.post.mk>
