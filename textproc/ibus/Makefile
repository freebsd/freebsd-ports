# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus
PORTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Input Bus for Linux / Unix OS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:${PORTSDIR}/devel/py-dbus \
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2 \
		setxkbmap:${PORTSDIR}/x11/setxkbmap
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_GNOME=	pygobject3
USE_PYTHON=	yes

USE_LDCONFIG=	yes
USES=		gmake pkgconfig compiler
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=	--disable-tests

OPTIONS_DEFINE=	ISOCODES NLS GTK2 GTK3 VALA GINTRO PYTHON_LIB DOC XIM ENGINE
OPTIONS_RADIO=	CONFIG
OPTIONS_RADIO_CONFIG=	GCONF DCONF
OPTIONS_DEFAULT=	ISOCODES NLS GTK2 GTK3 VALA GINTRO PYTHON_LIB DCONF XIM ENGINE

ISOCODES_DESC=	Use isocodecs
GTK2_DESC=	Install GTK2 client
GTK3_DESC=	Install GTK3 client and panel
VALA_DESC=	Install vala binding
GINTRO_DESC=	Install GObject Introspection data
PYTHON_LIB_DESC=	Install ibus Python libraries
GCONF_DESC=	Use GConf for configuration
DCONF_DESC=	Use dconf for configuration
DOC_DESC=	Install HTML documents
XIM_DESC=	Install XIM server
ENGINE_DESC=	Install ibus simple engine

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MISOCODES}
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS+=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:${PORTSDIR}/misc/iso-codes
.else
CONFIGURE_ARGS+=	--disable-iso-codes-check
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--enable-gtk2
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk2
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MGTK3}
# libnotify is used by the GTK3 UI module
CONFIGURE_ARGS+=	--enable-gtk3 --enable-libnotify
USE_GNOME+=	gtk30
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
PLIST_SUB+=	GTK3=""
.else
CONFIGURE_ARGS+=	--disable-gtk3 --disable-libnotify
PLIST_SUB+=	GTK3="@comment "
.endif

.if ${PORT_OPTIONS:MVALA}
CONFIGURE_ARGS+=	--enable-vala
BUILD_DEPENDS+=	vala-vapigen>=0.16:${PORTSDIR}/lang/vala-vapigen
PLIST_SUB+=	VALA=""
.else
CONFIGURE_ARGS+=	--disable-vala
PLIST_SUB+=	VALA="@comment "
.endif

.if ${PORT_OPTIONS:MGINTRO}
BUILD_DEPENDS+=		gobject-introspection>=0.6.8:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS+=		gobject-introspection>=0.6.8:${PORTSDIR}/devel/gobject-introspection
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST_SUB+=		GINTRO=""
.else
CONFIGURE_ARGS+=	--enable-introspection=no
PLIST_SUB+=		GINTRO="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON_LIB}
CONFIGURE_ARGS+=	--enable-python-library
PLIST_SUB+=		PYTHON_LIB=""
USE_GNOME+=	pygtk2
.else
CONFIGURE_ARGS+=	--disable-python-library
PLIST_SUB+=		PYTHON_LIB="@comment "
.endif

.if ${PORT_OPTIONS:MGCONF}
CONFIGURE_ARGS+=	--enable-gconf
PLIST_SUB+=		GCONF=""
GCONF_SCHEMAS=	ibus.schemas
USE_GNOME+=		gconf2
.else
CONFIGURE_ARGS+=	--disable-gconf
PLIST_SUB+=		GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MDCONF}
CONFIGURE_ARGS+=	--enable-dconf
PLIST_SUB+=		DCONF=""
GLIB_SCHEMAS=	org.freedesktop.ibus.gschema.xml
# gconf2 required for gsettings-schema-convert
USE_GNOME+=		dconf gconf2
.else
CONFIGURE_ARGS+=	--disable-dconf
PLIST_SUB+=		DCONF="@comment "
.endif

.if ${PORT_OPTIONS:MDOC}
CONFIGURE_ARGS+=	--enable-gtk-doc-html
PLIST_SUB+=		DOC=""
.else
CONFIGURE_ARGS+=	--disable-gtk-doc-html
PLIST_SUB+=		DOC="@comment "
.endif

.if ${PORT_OPTIONS:MXIM}
CONFIGURE_ARGS+=	--enable-xim
PLIST_SUB+=		XIM=""
.else
CONFIGURE_ARGS+=	--disable-xim
PLIST_SUB+=		XIM="@comment "
.endif

.if ${PORT_OPTIONS:MENGINE}
CONFIGURE_ARGS+=	--enable-engine
PLIST_SUB+=		ENGINE=""
.else
CONFIGURE_ARGS+=	--disable-engine
PLIST_SUB+=		ENGINE="@comment "
.endif

.if ${PORT_OPTIONS:MENGINE} || ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MGCONF} || ${PORT_OPTIONS:MDCONF}
PLIST_SUB+=	COMPDIR=""
.else
PLIST_SUB+=	COMPDIR="@comment "
.endif

# Workaround XIGrabKeycode/XIUngrabKeycode bug: XIAllMasterDevice does not work
.if !defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${FILESDIR}/extra-xigrabkeycode
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/var/lib/dbus|/var/db/dbus|g' ${WRKSRC}/src/ibusshare.c

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	@${INSTALL_DATA} ${PATCHDIR}/ibus.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.post.mk>
