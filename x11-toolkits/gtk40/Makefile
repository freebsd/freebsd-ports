PORTNAME=	gtk
PORTVERSION=	4.20.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)
WWW=		https://www.gtk.org/

LICENSE=	LGPL21+

BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
		iso-codes>0:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		sassc>0:textproc/sassc
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libgraphene-1.0.so:graphics/graphene \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	hicolor-icon-theme>0:misc/hicolor-icon-theme \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		compiler:c11 cpe gettext-tools gnome jpeg localbase meson \
		ninja pathfix perl5 python pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	atk cairo gdkpixbuf introspection:build pango \
		librsvg2
GLIB_SCHEMAS=	org.gtk.Demo4.gschema.xml \
		org.gtk.gtk4.Inspector.gschema.xml \
		org.gtk.gtk4.Settings.ColorChooser.gschema.xml \
		org.gtk.gtk4.Settings.Debug.gschema.xml \
		org.gtk.gtk4.Settings.EmojiChooser.gschema.xml \
		org.gtk.gtk4.Settings.FileChooser.gschema.xml
USE_LDCONFIG=	yes
USE_PERL5=	build
MESON_ARGS=	-Dbuild-testsuite=false
LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limit:1,even

LIBVERSION=	1.2000.3
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

OPTIONS_DEFINE=	ACCESSKIT BASH CUPS COLORD DEBUG BROADWAY GSTREAMER VULKAN \
		WAYLAND X11
OPTIONS_DEFAULT=CUPS COLORD GSTREAMER VULKAN WAYLAND X11
OPTIONS_EXCLUDE=	ACCESSKIT
OPTIONS_SUB=	yes

ACCESSKIT_DESC=	Enable AccessKit backend for accessibility (experimental)
BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK in the webbrowser using HTML5 and web sockets.
COLORD_DESC=	Color profile support
GSTREAMER_DESC=		GStreamer multimedia backend
VULKAN_DESC=		GDK Vulkan renderer backend
WAYLAND_DESC=		GDK Wayland backend
X11_DESC=		GDK X11 backend

ACCESSKIT_LIB_DEPENDS=	libaccesskit-c-0.17.so:accessibility/accesskit-c
ACCESSKIT_MESON_ENABLED=	accesskit

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion

BROADWAY_MESON_TRUE=	broadway-backend

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_ENABLED=	colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_ENABLED=	print-cups

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=bad,gl
GSTREAMER_MESON_ENABLED=media-gstreamer

VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_RUN_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VULKAN_MESON_ENABLED=	vulkan
VULKAN_CFLAGS=		-Wno-error=int-conversion # https://gitlab.gnome.org/GNOME/gtk/-/issues/6033

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl
WAYLAND_MESON_TRUE=	wayland-backend

X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
X11_USES=		xorg
X11_USE=		XORG=x11,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr,xrender
X11_MESON_TRUE=		x11-backend

pre-build:
	@${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/loaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/loaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/modules

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dbuild-testsuite=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
