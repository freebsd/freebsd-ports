PORTNAME=	liboqs
DISTVERSION=	0.10.1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for quantum-resistant cryptography
WWW=		https://openquantumsafe.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		bash:shells/bash

USES=		cmake:testing python:test shebangfix ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	open-quantum-safe

SHEBANG_GLOB=	*.sh

CMAKE_ON=	BUILD_SHARED_LIBS OQS_DIST_BUILD \
		OQS_PERMIT_UNSUPPORTED_ARCHITECTURE # trying to build on i386, powerpc, armv6, riscv64

CMAKE_TESTING_TARGET=	run_tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	KEM_BIKE="" # BIKE algorithm is limited by architecture in .CMake/alg_support.cmake
.else
PLIST_SUB+=	KEM_BIKE="@comment "
.endif

.include <bsd.port.mk>
