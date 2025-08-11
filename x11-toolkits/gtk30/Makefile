PORTNAME=	gtk
DISTVERSION=	3.24.50 # sync with x11-themes: adwaita-icon-theme, gnome-themes-standard and mate-themes
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Graphical UI toolkit (GTK3 library)
WWW=		https://www.gtk.org/

LICENSE=	LGPL21+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		hicolor-icon-theme>=0:misc/hicolor-icon-theme

USES=		compiler:c11 cpe gettext gnome localbase:ldflags meson ninja \
		pathfix perl5 pkgconfig python shebangfix tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	atk cairo gdkpixbuf gtk-update-icon-cache pango \
		introspection:build librsvg2:run
GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml
USE_LDCONFIG=	yes
USE_PERL5=	build
SHEBANG_GLOB=	*.py

MESON_ARGS=	-Dtests=false

PORTSCOUT=	limit:1,even

LIBVERSION=	0.2418.32
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

OPTIONS_DEFINE=		ATK_BRIDGE COLORD CUPS DOCS
OPTIONS_DEFAULT=	ATK_BRIDGE BROADWAY COLORD CUPS WAYLAND X11
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	BROADWAY WAYLAND X11
OPTIONS_SUB=		yes

ATK_BRIDGE_DESC=	AT-SPI ATK bridge support
BROADWAY_DESC=		Enable GDK Broadway backend for showing GTK in the webbrowser using HTML5 and web sockets.
COLORD_DESC=		Color profile support
WAYLAND_DESC=		GDK Wayland backend
X11_DESC=		GDK X11 backend

ATK_BRIDGE_IMPLIES=	X11
ATK_BRIDGE_LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core
ATK_BRIDGE_MESON_TRUE=	atk_bridge

BROADWAY_MESON_TRUE=	broadway_backend

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_YES=	colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_ON=		-Dprint_backends=cups,file,lpr
CUPS_MESON_OFF=		-Dprint_backends=file,lpr

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc man

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
WAYLAND_MESON_TRUE=	wayland_backend

X11_USES=	xorg
X11_USE=	XORG=x11,xcomposite,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr,xrender
X11_MESON_TRUE=	x11_backend

TESTING_UNSAFE=	ld: error: unable to find library -lintl

pre-build:
	@${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders

pre-test:
	${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}
	${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=true"

.include <bsd.port.mk>
