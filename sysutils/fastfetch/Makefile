PORTNAME=	fastfetch
DISTVERSION=	2.71.0
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Like neofetch, but much faster because written in C
WWW=		https://github.com/fastfetch-cli/fastfetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libyyjson.so:devel/yyjson
RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		cmake:testing localbase:ldflags pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	fastfetch-cli

OPTIONS_DEFINE=	VULKAN WAYLAND XCB XRANDR LIBDRM GIO DCONF EET DBUS \
		SQLITE3 IMAGEMAGICK CHAFA EGL GLX OPENCL CODEC LUA

OPTIONS_DEFAULT=VULKAN WAYLAND XCB XRANDR LIBDRM GIO DCONF EET DBUS \
		SQLITE3 IMAGEMAGICK CHAFA EGL GLX OPENCL CODEC LUA

DCONF_DESC=	Needed for values that are only stored in DConf + Fallback for GSettings
EET_DESC=	Theme, icon and font detection in Enlightenment
CHAFA_DESC=	Image output as ascii art
EGL_DESC=	OpenGL and GPU detection via EGL
LIBDRM_DESC=	Enable display server detection via libdrm
VULKAN_DESC=	Vulkan module & fallback for GPU output
XCB_DESC=	Display and WM detection in X11 via xcb-randr
XRANDR_DESC=	Needed for display and WM detection in X11
CODEC_DESC=	Hardware video codec detection (VA-API, VDPAU)
LUA_DESC=	Lua scripting support for format strings

VULKAN_CMAKE_BOOL=	ENABLE_VULKAN
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/lib/libwayland-client.so:graphics/wayland

XCB_CMAKE_BOOL=	ENABLE_XCB_RANDR
XCB_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-randr.pc:x11/libxcb

XRANDR_CMAKE_BOOL=	ENABLE_XRANDR
XRANDR_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr

LIBDRM_CMAKE_BOOL=	ENABLE_DRM
LIBDRM_BUILD_DEPENDS=	${LOCALBASE}/lib/libdrm.so:graphics/libdrm

GIO_CMAKE_BOOL=	ENABLE_GIO
GIO_BUILD_DEPENDS=	${LOCALBASE}/lib/libgio-2.0.so:devel/glib20

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_BUILD_DEPENDS=	${LOCALBASE}/lib/libdbus-1.so:devel/dbus

DCONF_CMAKE_BOOL=	ENABLE_DCONF
DCONF_BUILD_DEPENDS=	${LOCALBASE}/lib/libdconf.so:devel/dconf

EET_CMAKE_BOOL=	ENABLE_EET
EET_BUILD_DEPENDS=	${LOCALBASE}/lib/libeet.so:devel/efl

SQLITE3_CMAKE_BOOL=	ENABLE_SQLITE3
SQLITE3_USES=		sqlite

IMAGEMAGICK_CMAKE_BOOL=	ENABLE_IMAGEMAGICK7
IMAGEMAGICK_USES=	magick:7,build

CHAFA_IMPLIES=	IMAGEMAGICK
CHAFA_CMAKE_BOOL=	ENABLE_CHAFA
CHAFA_BUILD_DEPENDS=	${LOCALBASE}/lib/libchafa.so:graphics/chafa

EGL_CMAKE_BOOL=	ENABLE_EGL
EGL_BUILD_DEPENDS=	${LOCALBASE}/lib/libEGL.so:graphics/libglvnd

GLX_CMAKE_BOOL=	ENABLE_GLX
GLX_BUILD_DEPENDS=	${LOCALBASE}/lib/libGLX.so:graphics/libglvnd

OPENCL_CMAKE_BOOL=	ENABLE_OPENCL
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenCL.so:devel/ocl-icd \
			${LOCALBASE}/include/CL/cl.h:devel/opencl

LUA_CMAKE_BOOL=	ENABLE_LUA
LUA_USES=		lua:build

CODEC_CMAKE_BOOL=	ENABLE_VADRM ENABLE_VAX11 ENABLE_VDPAU
CODEC_BUILD_DEPENDS=	${LOCALBASE}/lib/libva.so:multimedia/libva \
			${LOCALBASE}/lib/libvdpau.so:multimedia/libvdpau

CMAKE_ARGS=	-DTARGET_DIR_ETC:STRING="${LOCALBASE}/etc" \
		-DENABLE_SYSTEM_YYJSON:BOOL=ON \
		-DENABLE_IMAGEMAGICK6:BOOL=OFF \
		-DBUILD_FLASHFETCH:BOOL=OFF

CMAKE_TESTING_ON=	BUILD_TESTS

.include <bsd.port.mk>
