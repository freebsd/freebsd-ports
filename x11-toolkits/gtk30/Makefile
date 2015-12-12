# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.16.7
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
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
LIB_DEPENDS=	libepoxy.so:${PORTSDIR}/graphics/libepoxy
RUN_DEPENDS+=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:${PORTSDIR}/x11-themes/adwaita-icon-theme \
		at-spi2-atk>=0:${PORTSDIR}/accessibility/at-spi2-atk

USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk gdkpixbuf2 introspection:build pango
#gtk-update-icon-cache \
#		introspection:build pango
USES+=		gettext gmake libtool pathfix perl5 pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-x11-backend \
		--disable-wayland-backend \
		--enable-introspection
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

LIBVERSION=	0.1600.7
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

OPTIONS_DEFINE=	CUPS CLOUDPRINT COLORD DEBUG BROADWAY TYPEAHEAD
OPTIONS_DEFAULT=CUPS COLORD BROADWAY
OPTIONS_SUB=	yes

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_CONFIGURE_ENABLE=	broadway-backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:${PORTSDIR}/graphics/colord
COLORD_CONFIGURE_ENABLE=colord

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
CUPS_CONFIGURE_ENABLE=	cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_CONFIGURE_ENABLE=	cloudprint
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:${PORTSDIR}/devel/librest \
			libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

DEBUG_CONFIGURE_ENABLE=debug

# GTK+ 3.17 has a beter way
TYPEAHEAD_DESC=		Re-enable type-a-head functionality in file chooser
TYPEAHEAD_EXTRA_PATCHES=${FILESDIR}/extra-gtk_gtkfilechooserwidget.c \
		${FILESDIR}/extra-gtk_ui_gtkfilechooserwidget.ui

post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|file,cups|file,cups,lpr|' \
		${WRKSRC}/gtk/Makefile.in

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

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
