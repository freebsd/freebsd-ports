# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.22.15
PORTREVISION?=	2
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

BUILD_DEPENDS+=	at-spi2-atk>=0:accessibility/at-spi2-atk
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		at-spi2-atk>=0:accessibility/at-spi2-atk \
		librsvg2>=0:graphics/librsvg2

USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango
#gtk-update-icon-cache
USES+=		compiler:c11 gettext gmake gnome libtool localbase \
		pathfix perl5 pkgconfig
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--enable-x11-backend \
		--disable-wayland-backend \
		--enable-introspection
CPPFLAGS+=	-fno-omit-frame-pointer
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

LIBVERSION=	0.2200.15
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

OPTIONS_DEFINE=	CUPS CLOUDPRINT COLORD DEBUG BROADWAY
OPTIONS_DEFAULT=CUPS COLORD BROADWAY
OPTIONS_SUB=	yes

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_CONFIGURE_ENABLE=	broadway-backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_CONFIGURE_ENABLE=colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=	cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_CONFIGURE_ENABLE=	cloudprint
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libjson-glib-1.0.so:devel/json-glib

# don't explicitly disable debug, this causes segfaults. ports r437293
DEBUG_CONFIGURE_ON=	--enable-debug=yes

post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

pre-build:
	@${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders
	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-3.0.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

.endif
