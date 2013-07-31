# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtk30/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gtk
PORTVERSION=	3.8.2
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

USE_XZ=		yes
LATEST_LINK=	gtk30

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/atk-bridge-2.0.pc:${PORTSDIR}/accessibility/at-spi2-atk
BUILD_DEPENDS+=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/atk-bridge-2.0.pc:${PORTSDIR}/accessibility/at-spi2-atk

USE_PERL5_BUILD=yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	atk pango gdkpixbuf2 ltverhack gtk-update-icon-cache
#		introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-gtk2-dependency --disable-packagekit
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	INTROSPECTION_GIRDIR=`pkg-config --variable=girdir gobject-introspection-1.0`

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

MAN1=		gtk-query-immodules-3.0.1

OPTIONS_DEFINE=	CUPS COLORD DEBUG
OPTIONS_DEFAULT=CUPS COLORD
COLORD_DESC=	Color profile support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
CONFIGURE_ARGS+=--enable-cups=auto
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

.if ${PORT_OPTIONS:MCOLORD}
LIB_DEPENDS+=	colord:${PORTSDIR}/graphics/colord
CONFIGURE_ARGS+=--enable-colord
.else
CONFIGURE_ARGS+=--disable-colord
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${GREP} -l lgmodule | \
		${XARGS} ${REINPLACE_CMD} -e 's|-lgmodule|@GMODULE_LIBS@|g'
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@LN_S@|${LN} -sf|' ${WRKSRC}/gtk/Makefile.in
	@${REINPLACE_CMD} -e 's|file,cups|file,cups,lpr|' \
		${WRKSRC}/gtk/Makefile.in

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-xlib.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with X11 support enabled."
	@${FALSE}
.endif

pre-build:
	@${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	-@${FIND} ${LOCALBASE}/share/icons -type d -depth 1 -exec \
		${PREFIX}/bin/gtk-update-icon-cache -q -f {} \; 2>/dev/null
	@${MKDIR} ${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/docs/reference/gtk/|} \
		${PREFIX}/man/man1

.include <bsd.port.mk>

.endif
