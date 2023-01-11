PORTNAME=	clingo
DISTVERSION=	5.6.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs
WWW=		https://potassco.org/clingo/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR}

USES=		compiler:c++14-lang python:3.6+
USE_PYTHON=	distutils autoplist unittest # some tests break, see https://github.com/potassco/clingo/issues/390

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/clingo
TEST_WRKSRC=	${WRKSRC}/libpyclingo

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/clingo/_clingo${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
