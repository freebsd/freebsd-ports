# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtk30/Makefile 19813 2014-08-15 19:44:33Z gusi $
# Please keep gtk30 and x11-themes/gnome-themes-standard minor version in sync

PORTNAME=	gtk
PORTVERSION=	3.12.2
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

USES=		tar:xz

.if defined(REFERENCE_PORT)
PORTSCOUT=	ignore:1
.else
PORTSCOUT=	limit:1,even

BUILD_DEPENDS+=	at-spi2-atk>=0:${PORTSDIR}/accessibility/at-spi2-atk
RUN_DEPENDS+=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme \
		at-spi2-atk>=0:${PORTSDIR}/accessibility/at-spi2-atk

USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk gdkpixbuf2 gtk-update-icon-cache \
		introspection:build pango
USES+=		gettext gmake libtool pathfix perl5 pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-gtk2-dependency --disable-packagekit \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

LIBVERSION=	0.1200.2
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
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_CHECKS||' \
		${WRKSRC}/configure

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

.include <bsd.port.mk>

.endif
