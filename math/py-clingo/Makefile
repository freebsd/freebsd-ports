PORTNAME=	clingo
DISTVERSION=	5.8.3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs
WWW=		https://potassco.org/clingo/ \
		https://github.com/potassco/clingo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	pep517 autoplist unittest

MAKE_ENV+=	CMAKE_ARGS=-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/potassco/clingo/issues/677

TEST_WRKSRC=	${WRKSRC}/libpyclingo

post-stage:
	@${CP} ${STAGEDIR}${PYTHON_SITELIBDIR}/clingo/_clingo${PYTHON_SOABI}.so ${WRKSRC}/libpyclingo/clingo/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/clingo/_clingo${PYTHON_TAG}.so

# tests as of 5.8.3: 75 tests in 0.338s

.include <bsd.port.mk>
