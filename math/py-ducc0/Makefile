PORTNAME=	ducc0
DISTVERSION=	0.24.0
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

USES=		compiler:c++17-lang python:3.6+

USE_PYTHON=	distutils autoplist

MAKE_ENV=	DUCC0_OPTIMIZATION=none

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ducc0*.so

do-test: install
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
