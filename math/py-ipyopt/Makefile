PORTNAME=	ipyopt
DISTVERSION=	0.12.9
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to Ipopt
WWW=		https://gitlab.com/g-braeunlich/ipyopt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libipopt.so:math/ipopt
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c++17-lang pkgconfig python
USE_PYTHON=	distutils autoplist pytest

CXXFLAGS+=	$(pkg-config --cflags ipopt)

TEST_ENV=      ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cpython-*.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest

.include <bsd.port.mk>
