# New ports collection makefile for:	ibus
# Date created:				21 October 2008
# Whom:					Henry Hu <henry.hu.sh@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Input Bus for Linux / Unix OS

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:${PORTSDIR}/devel/py-dbus \
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83.0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_PYTHON=	yes
USE_GNOME=	pygtk2 gconf2

USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	ibus.schemas

OPTIONS=	ISOCODES "Use isocodecs" on \
		GTK3 "Install GTK3 client" on \
		VALA "Install vala binding" on \
		GINTRO "Install GObject Introspection data" on

.include <bsd.port.pre.mk>

.if defined(WITH_ISOCODES)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS+=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:${PORTSDIR}/misc/iso-codes
.else
CONFIGURE_ARGS+=	--disable-iso-codes-check
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_GTK3)
CONFIGURE_ARGS+=	--disable-gtk3
PLIST_SUB+=	GTK3="@comment "
.else
USE_GNOME+=	gtk30
PLIST_SUB+=	GTK3=""
.endif

.if defined(WITH_VALA)
CONFIGURE_ARGS+=	--enable-vala
PLIST_SUB+=	VALA=""
.else
CONFIGURE_ARGS+=	--disable-vala
PLIST_SUB+=	VALA="@comment "
.endif

.if defined(WITH_GINTRO)
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
	@${MKDIR} ${PREFIX}/etc/xdg/autostart
	@${INSTALL_DATA} ${WRKSRC}/bus/ibus.desktop ${PREFIX}/etc/xdg/autostart
.	if defined(WITH_GTK3)
		@gtk-query-immodules-3.0 --update-cache
.	endif
	@gtk-query-immodules-2.0 > ${LOCALBASE}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
