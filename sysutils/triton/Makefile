PORTNAME=	triton
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9-597
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gafb28564
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Binary Analysis (DBA) framework
WWW=		https://triton.quarkslab.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	src/libtriton/includes/triton/tritonToZ3.hpp:43:17: error: no type named '__uint' in namespace 'triton', see https://github.com/JonathanSalwan/Triton/issues/1214
BROKEN_i386=	compilation fails: conflict of 'namespace i386' and macro '#define i386 1'
BROKEN_riscv64=	src/libtriton/includes/triton/tritonToZ3.hpp:43:17: error: no type named '__uint' in namespace 'triton', see https://github.com/JonathanSalwan/Triton/issues/1214

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libz3.so:math/z3

USES=		cmake:testing compiler:c++17-lang shebangfix
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	JonathanSalwan
GH_PROJECT=	Triton

CMAKE_TESTING_ON=	ENABLE_TEST

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CMAKE_BOOL=	PYTHON_BINDINGS
PYTHON_CMAKE_ON=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}
PYTHON_TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lief>0:devel/py-lief@${PY_FLAVOR}

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/triton.so

.include <bsd.port.mk>
