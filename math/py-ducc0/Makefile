PORTNAME=	ducc0
DISTVERSION=	0.22.0
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distinctly Useful Code Collection (DUCC)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	non-constant-expression cannot be narrowed from type 'long long' to 'int' in initializer list (reported to the author on 2021-05-02 and 2022-02-01)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+

USE_PYTHON=	distutils autoplist

MAKE_ENV=	DUCC0_OPTIMIZATION=none

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CFLAGS+=	-DNO_WARN_X86_INTRINSICS
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++17-lang
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ducc0*.so

do-test: install
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
