PORTNAME=	fastfetch
DISTVERSION=	2.3.4
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Like neofetch, but much faster because written in C
WWW=		https://github.com/fastfetch-cli/fastfetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyyjson.so:devel/yyjson

FLAVORS=	full lite
FLAVOR?=	${FLAVORS:[1]}
lite_PKGNAMESUFFIX=	-lite

USES=		cmake:testing localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fastfetch-cli

OPTIONS_DEFINE=	LIBPCI VULKAN WAYLAND XCB GIO DCONF DBUS XFCONF \
		SQLITE3 IMAGEMAGICK CHAFA GLX OPENCL PULSEAUDIO

.if ${FLAVOR} == full
OPTIONS_DEFAULT=	VULKAN WAYLAND XCB GIO DCONF DBUS XFCONF \
		SQLITE3 IMAGEMAGICK CHAFA GLX OPENCL PULSEAUDIO
.endif

DCONF_DESC=	Needed for values that are only stored in DConf + Fallback for GSettings
CHAFA_DESC=	Image output as ascii art
LIBPCI_DESC=	GPU output
VULKAN_DESC=	Vulkan module & fallback for GPU output
XCB_DESC=	Needed for display and WM detection in X11
XFCONF_DESC=	Needed for XFWM theme and XFCE Terminal font

LIBPCI_CMAKE_BOOL=	ENABLE_LIBPCI
LIBPCI_BUILD_DEPENDS=	${LOCALBASE}/lib/libpci.so:devel/libpci
LIBPCI_RUN_DEPENDS=	${LOCALBASE}/lib/libpci.so:devel/libpci

VULKAN_CMAKE_BOOL=	ENABLE_VULKAN
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/lib/libwayland-server.so:graphics/wayland
WAYLAND_RUN_DEPENDS=	${LOCALBASE}/lib/libwayland-server.so:graphics/wayland

XCB_CMAKE_BOOL=	ENABLE_XCB ENABLE_XCB_RANDR
XCB_BUILD_DEPENDS=	${LOCALBASE}/lib/libxcb-randr.so:x11/libxcb
XCB_RUN_DEPENDS=	${LOCALBASE}/lib/libxcb-randr.so:x11/libxcb

GIO_CMAKE_BOOL=	ENABLE_GIO
GIO_BUILD_DEPENDS=	${LOCALBASE}/lib/libgio-2.0.so:devel/glib20
GIO_RUN_DEPENDS=	${LOCALBASE}/lib/libgio-2.0.so:devel/glib20

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_BUILD_DEPENDS=	${LOCALBASE}/lib/libdbus-1.so:devel/dbus
DBUS_RUN_DEPENDS=	${LOCALBASE}/lib/libdbus-1.so:devel/dbus

DCONF_CMAKE_BOOL=	ENABLE_DCONF
DCONF_BUILD_DEPENDS=	${LOCALBASE}/lib/libdconf.so:devel/dconf
DCONF_RUN_DEPENDS=	${LOCALBASE}/lib/libdconf.so:devel/dconf

XFCONF_CMAKE_BOOL=	ENABLE_XFCONF
XFCONF_BUILD_DEPENDS=	${LOCALBASE}/lib/libxfconf-0.so:x11/xfce4-conf
XFCONF_RUN_DEPENDS=	${LOCALBASE}/lib/libxfconf-0.so:x11/xfce4-conf

SQLITE3_CMAKE_BOOL=	ENABLE_SQLITE3
SQLITE3_BUILD_DEPENDS=	${LOCALBASE}/lib/libsqlite3.so:databases/sqlite3
SQLITE3_RUN_DEPENDS=	${LOCALBASE}/lib/libsqlite3.so:databases/sqlite3

IMAGEMAGICK_CMAKE_BOOL=	ENABLE_IMAGEMAGICK7
IMAGEMAGICK_USES=	magick:7,build,run

CHAFA_IMPLIES=	IMAGEMAGICK
CHAFA_CMAKE_BOOL=	ENABLE_CHAFA
CHAFA_BUILD_DEPENDS=	${LOCALBASE}/lib/libchafa.so:graphics/chafa
CHAFA_RUN_DEPENDS=	${LOCALBASE}/lib/libchafa.so:graphics/chafa

GLX_CMAKE_BOOL=	ENABLE_GLX
GLX_BUILD_DEPENDS=	${LOCALBASE}/lib/libGLX.so:graphics/libglvnd
GLX_RUN_DEPENDS=	${LOCALBASE}/lib/libGLX.so:graphics/libglvnd

OPENCL_CMAKE_BOOL=	ENABLE_OPENCL
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenCL.so:devel/ocl-icd \
			${LOCALBASE}/include/CL/cl.h:devel/opencl
OPENCL_RUN_DEPENDS=	${LOCALBASE}/lib/libOpenCL.so:devel/ocl-icd

PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSE
PULSEAUDIO_BUILD_DEPENDS=	${LOCALBASE}/lib/libpulse.so:audio/pulseaudio
PULSEAUDIO_RUN_DEPENDS=	${LOCALBASE}/lib/libpulse.so:audio/pulseaudio

CMAKE_ARGS=	-DTARGET_DIR_ETC:STRING="${LOCALBASE}/etc" \
		-DENABLE_SYSTEM_YYJSON:BOOL=ON

CMAKE_TESTING_ON=	BUILD_TESTS

.include <bsd.port.mk>
