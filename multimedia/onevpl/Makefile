PORTNAME=	oneVPL
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.0.6
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	oneAPI Video Processing Library dispatcher, tools, and examples

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libva.so:multimedia/libva

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb
GH_ACCOUNT=	oneapi-src
CMAKE_TESTING_ON=	BUILD_TESTS

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11
PYTHON_CMAKE_BOOL=	BUILD_PYTHON_BINDING
PYTHON_CMAKE_ON=	-DPython3_EXECUTABLE:FILEPATH="${PYTHON_CMD}"

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,FULL_LIBDIR},PREFIX}/libdata,' \
		${WRKSRC}/dispatcher/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		${WRKSRC}/dispatcher/vpl/mfx_dispatcher_vpl_loader.cpp
	@${REINPLACE_CMD} -e '/PKG_CONFIG/s,_lib,_prefix/libdata,' \
		${WRKSRC}/modulefiles/vpl

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e '/LIBDIR/s/python/&${PYTHON_VER}/' \
		${WRKSRC}/preview/python/binding/CMakeLists.txt

post-install:
	@${FIND} ${STAGEDIR} -name \*.orig -delete

.include <bsd.port.mk>
