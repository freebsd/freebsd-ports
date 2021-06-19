# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.24.29
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

PORTSCOUT=	limit:1,even

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme

USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango \
		librsvg2:run
USES=		compiler:c11 gettext gmake gnome libtool localbase \
		pathfix perl5 pkgconfig tar:xz
CONFIGURE_ARGS=	--enable-introspection
CPPFLAGS+=	-fno-omit-frame-pointer
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

LIBVERSION=	0.2404.25
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

OPTIONS_DEFINE=	ATK_BRIDGE CUPS CLOUDPRINT COLORD DEBUG BROADWAY WAYLAND X11
OPTIONS_DEFAULT=ATK_BRIDGE CUPS COLORD BROADWAY WAYLAND X11
OPTIONS_SUB=	yes

ATK_BRIDGE_DESC=AT-SPI ATK bridge support (requires X11)
ATK_BRIDGE_CONFIGURE_WITH=	atk-bridge
ATK_BRIDGE_LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk
ATK_BRIDGE_IMPLIES=	X11

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_CONFIGURE_ENABLE=	broadway-backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_CONFIGURE_ENABLE=colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=	cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_CONFIGURE_ENABLE=	cloudprint
CLOUDPRINT_USE=		gnome=libxml2
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libsoup-2.4.so:devel/libsoup \
			libjson-glib-1.0.so:devel/json-glib

# don't explicitly disable debug, this causes segfaults. See ports r437293
DEBUG_CONFIGURE_ON=	--enable-debug=yes

WAYLAND_DESC=		GDK Wayland backend
WAYLAND_CONFIGURE_ENABLE=	wayland-backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl

X11_DESC=		GDK X11 backend
X11_CONFIGURE_ENABLE=	x11-backend
X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr,xrender

post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure

pre-configure-X11-on:
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
