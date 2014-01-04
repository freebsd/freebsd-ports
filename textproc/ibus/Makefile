# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus
PORTVERSION=	1.4.2
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
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_PYTHON=	yes
USE_GNOME=	pygtk2 gconf2

USE_LDCONFIG=	yes
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	ibus.schemas

OPTIONS_DEFINE=	ISOCODES NLS GTK3 VALA GINTRO
OPTIONS_DEFAULT=	ISOCODES GTK3 VALA GINTRO

ISOCODES_DESC=	Use isocodecs
GTK3_DESC=	Install GTK3 client
VALA_DESC=	Install vala binding
GINTRO_DESC=	Install GObject Introspection data

.include <bsd.port.options.mk>

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

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
PLIST_SUB+=	GTK3=""
.else
CONFIGURE_ARGS+=	--disable-gtk3
PLIST_SUB+=	GTK3="@comment "
.endif

.if ${PORT_OPTIONS:MVALA}
CONFIGURE_ARGS+=	--enable-vala
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

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share/xml/iso-codes/|${LOCALBASE}/share/xml/iso-codes/|g' ${WRKSRC}/ibus/lang.py
	@${REINPLACE_CMD} -e 's|locale.bind_textdomain_codeset|gettext.bind_textdomain_codeset|g' ${WRKSRC}/setup/main.py
	@${REINPLACE_CMD} -e 's|locale.bind_textdomain_codeset|gettext.bind_textdomain_codeset|g' ${WRKSRC}/ui/gtk/main.py
	@${REINPLACE_CMD} -e 's|import locale|import gettext|g' ${WRKSRC}/ui/gtk/main.py
	@${REINPLACE_CMD} -e 's|setpgrp ()|setpgrp (0,0)|g' ${WRKSRC}/bus/main.c
	@${REINPLACE_CMD} -e 's|/var/lib/dbus|/var/db/dbus|g' ${WRKSRC}/src/ibusshare.c #devel/dbus/files/dbus.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	@${INSTALL_DATA} ${WRKSRC}/bus/ibus.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.mk>
