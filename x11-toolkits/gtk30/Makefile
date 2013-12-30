# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtk30/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gtk
PORTVERSION=	3.8.8
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

USE_XZ=		yes

.if defined(REFERENCE_PORT)
PORTSCOUT=	ignore:1
.else
PORTSCOUT=	limit:1,even

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/atk-bridge-2.0.pc:${PORTSDIR}/accessibility/at-spi2-atk
RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/atk-bridge-2.0.pc:${PORTSDIR}/accessibility/at-spi2-atk

USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk pango gdkpixbuf2 ltverhack gtk-update-icon-cache \
		introspection:build
USES=		gettext gmake pathfix perl5 pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-gtk2-dependency --disable-packagekit
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	INTROSPECTION_GIRDIR=`pkg-config --variable=girdir gobject-introspection-1.0`
ltverhack_PATCH_FILES=build-aux/ltmain.sh

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

OPTIONS_DEFINE=	CUPS COLORD DEBUG
OPTIONS_DEFAULT=CUPS COLORD
COLORD_DESC=	Color profile support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
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
LIB_DEPENDS+=	libcolord.so:${PORTSDIR}/graphics/colord
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders
	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-3.0.1 \
		${STAGEDIR}${PREFIX}/man/man1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdk-3.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtk-3.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgailutil-3.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/3.0.0/immodules/im*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/3.0.0/printbackends/libprintbackend-*.so

.include <bsd.port.mk>

.endif
