PORTNAME=	cpptoml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	textproc devel

MAINTAINER=	flo@purplekraken.com
COMMENT=	Header-only C++ library for parsing TOML
WWW=		https://github.com/skystrife/cpptoml/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	skystrife

CMAKE_OFF=	CPPTOML_BUILD_EXAMPLES ENABLE_LIBCXX

NO_ARCH=	yes

PLIST_FILES=	include/cpptoml.h \
		lib/cmake/cpptoml/cpptomlConfig.cmake \
		lib/cmake/cpptoml/cpptomlConfigVersion.cmake \
		lib/cmake/cpptoml/cpptomlTargets.cmake

.include <bsd.port.mk>
