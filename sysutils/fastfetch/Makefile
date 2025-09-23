PORTNAME=	fastfetch
DISTVERSION=	2.53.0
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Like neofetch, but much faster because written in C
WWW=		https://github.com/fastfetch-cli/fastfetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libyyjson.so:devel/yyjson
RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		cmake:testing localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fastfetch-cli

OPTIONS_DEFINE=	VULKAN WAYLAND XRANDR LIBDRM GIO DCONF DBUS SQLITE3 \
		IMAGEMAGICK CHAFA GLX OPENCL

OPTIONS_DEFAULT=VULKAN WAYLAND XRANDR LIBDRM GIO DCONF DBUS SQLITE3 \
		IMAGEMAGICK CHAFA GLX OPENCL

DCONF_DESC=	Needed for values that are only stored in DConf + Fallback for GSettings
CHAFA_DESC=	Image output as ascii art
LIBDRM_DESC=	Enable display server detection via libdrm
VULKAN_DESC=	Vulkan module & fallback for GPU output
XRANDR_DESC=	Needed for display and WM detection in X11

VULKAN_CMAKE_BOOL=	ENABLE_VULKAN
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/lib/libwayland-server.so:graphics/wayland

XRANDR_CMAKE_BOOL=	ENABLE_XRANDR
XRANDR_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr:x11/libXrandr

LIBDRM_CMAKE_BOOL=	ENABLE_DRM
LIBDRM_BUILD_DEPENDS=	${LOCALBASE}/lib/libdrm.so:graphics/libdrm

GIO_CMAKE_BOOL=	ENABLE_GIO
GIO_BUILD_DEPENDS=	${LOCALBASE}/lib/libgio-2.0.so:devel/glib20

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_BUILD_DEPENDS=	${LOCALBASE}/lib/libdbus-1.so:devel/dbus

DCONF_CMAKE_BOOL=	ENABLE_DCONF
DCONF_BUILD_DEPENDS=	${LOCALBASE}/lib/libdconf.so:devel/dconf

SQLITE3_CMAKE_BOOL=	ENABLE_SQLITE3
SQLITE3_BUILD_DEPENDS=	${LOCALBASE}/lib/libsqlite3.so:databases/sqlite3

IMAGEMAGICK_CMAKE_BOOL=	ENABLE_IMAGEMAGICK7
IMAGEMAGICK_USES=	magick:7,build

CHAFA_IMPLIES=	IMAGEMAGICK
CHAFA_CMAKE_BOOL=	ENABLE_CHAFA
CHAFA_BUILD_DEPENDS=	${LOCALBASE}/lib/libchafa.so:graphics/chafa

GLX_CMAKE_BOOL=	ENABLE_GLX
GLX_BUILD_DEPENDS=	${LOCALBASE}/lib/libGLX.so:graphics/libglvnd

OPENCL_CMAKE_BOOL=	ENABLE_OPENCL
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenCL.so:devel/ocl-icd \
			${LOCALBASE}/include/CL/cl.h:devel/opencl

CMAKE_ARGS=	-DTARGET_DIR_ETC:STRING="${LOCALBASE}/etc" \
		-DENABLE_SYSTEM_YYJSON:BOOL=ON \
		-DBUILD_FLASHFETCH:BOOL=OFF

CMAKE_TESTING_ON=	BUILD_TESTS

.include <bsd.port.mk>
