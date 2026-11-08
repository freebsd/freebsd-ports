PORTNAME=	libvpl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.17.0
CATEGORIES=	multimedia

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Intel Video Processing Library API, dispatcher, and examples
WWW=		https://www.intel.com/content/www/us/en/developer/tools/vpl/overview.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

USES=		cmake:testing compiler:c++14-lang localbase:ldflags pkgconfig pathfix
PATHFIX_CMAKELISTSTXT=CMakeLists.txt InstallDirs.cmake
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	BUILD_TESTS
CONFLICTS_INSTALL=	onevpl
DATADIR=	${PREFIX}/share/vpl

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/libvpl/src/mfx_dispatcher_vpl_loader.cpp
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/libvpl/src/mfx_dispatcher_vpl_lowlatency.cpp

post-install:
	@${FIND} ${STAGEDIR} -name \*.orig -delete

.include <bsd.port.mk>
