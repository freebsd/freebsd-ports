PORTNAME=	imgui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.92.1
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bloat-free Graphical User interface for C++ with minimal dependencies
WWW=		https://github.com/ocornut/imgui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ocornut

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=			FREETYPE WCHAR32
OPTIONS_MULTI=			BACKENDS
OPTIONS_MULTI_BACKENDS=		ALLEGRO5 GLFW OPENGL2 OPENGL3 SDL2 SDL2_RENDERER VULKAN
OPTIONS_DEFAULT=		GLFW OPENGL2 OPENGL3
OPTIONS_SUB=			yes

## general options

FREETYPE_CMAKE_BOOL=		IMGUI_FREETYPE
FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2

WCHAR32_DESC=			Use wchar32
WCHAR32_CMAKE_BOOL=		IMGUI_USE_WCHAR32

## backend options

ALLEGRO5_DESC=			Install Allegro5 backend
ALLEGRO5_CMAKE_BOOL=		IMGUI_BUILD_ALLEGRO5_BINDING
ALLEGRO5_LIB_DEPENDS=		liballegro.so:devel/allegro5 # even though binary doesn't link to liballegro.so for some reason

GLFW_DESC=			Install GLFW backend
GLFW_CMAKE_BOOL=		IMGUI_BUILD_GLFW_BINDING
GLFW_USES=			gl
GLFW_USE=			GL=gl
GLFW_LIB_DEPENDS=		libglfw.so:graphics/glfw

OPENGL2_DESC=			Install OPENGL2 backend
OPENGL2_USES=			gl localbase
OPENGL2_USE=			GL=gl
OPENGL2_CMAKE_BOOL=		IMGUI_BUILD_OPENGL2_BINDING

OPENGL3_DESC=			Install OPENGL3 backend
OPENGL3_USES=			gl localbase
OPENGL3_USE=			GL=gl
OPENGL3_CMAKE_BOOL=		IMGUI_BUILD_OPENGL3_BINDING

SDL2_DESC=			Install SDL2 backend
SDL2_USES=			localbase sdl
SDL2_USE=			SDL=sdl2
SDL2_CMAKE_BOOL=		IMGUI_BUILD_SDL2_BINDING

SDL2_RENDERER_DESC=		Install SDL2 renderer backend
SDL2_RENDERER_USES=		sdl
SDL2_RENDERER_USE=		SDL=sdl2
SDL2_RENDERER_CMAKE_BOOL=	IMGUI_BUILD_SDL2_RENDERER_BINDING

VULKAN_DESC=			Install Vulkan renderer backend
VULKAN_CMAKE_BOOL=		IMGUI_BUILD_VULKAN_BINDING
VULKAN_LIB_DEPENDS=		libvulkan.so:graphics/vulkan-loader

post-patch:
	@${CP} ${FILESDIR}/CMakeLists.txt ${FILESDIR}/imgui-config.cmake.in ${WRKSRC}

do-test:
	@cd ${WRKSRC}/examples/example_sdl2_opengl3 && \
		${GMAKE} \
			CXXFLAGS="${CXXFLAGS} `pkg-config --cflags sdl2` -I${STAGEDIR}${PREFIX}/include -I${WRKSRC}/backends" \
			LIBS="`pkg-config --libs sdl2` -lGL" && \
		./example_sdl2_opengl3

.include <bsd.port.mk>
