# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtk30/Makefile 18610 2013-06-30 16:33:05Z marcus $
# Please keep gtk30 and x11-themes/gnome-themes-standard minor version in sync

PORTNAME=	gtk
PORTVERSION=	3.10.7
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
USE_GNOME=	atk pango gdkpixbuf2 gtk-update-icon-cache \
		introspection:build
USES=		gettext gmake libtool pathfix perl5 pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-gtk2-dependency --disable-packagekit
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib

LIBVERSION=	0.1000.7
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml \
		org.gtk.exampleapp.gschema.xml

OPTIONS_DEFINE=	CUPS COLORD DEBUG
OPTIONS_DEFAULT=CUPS COLORD
OPTIONS_SUB=	yes
COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:${PORTSDIR}/graphics/colord
COLORD_CONFIGURE_ENABLE=colord
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
CUPS_CONFIGURE_ENABLE=	cups
DEBUG_CONFIGURE_ENABLE=debug

# needed for the exists() check, booo
.include <bsd.port.options.mk>

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
