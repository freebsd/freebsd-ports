PORTNAME=	triton
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Binary Analysis (DBA) framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	src/libtriton/includes/triton/tritonToZ3.hpp:43:17: error: no type named '__uint' in namespace 'triton'

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libz3.so:math/z3

USES=		cmake compiler:c++14-lang shebangfix
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	JonathanSalwan
GH_PROJECT=	Triton

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_CMAKE_BOOL=	PYTHON_BINDINGS

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/triton.so

.include <bsd.port.mk>
