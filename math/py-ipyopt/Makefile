PORTNAME=	ipyopt
DISTVERSION=	0.12.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to Ipopt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libipopt.so:math/ipopt
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++17-lang pkgconfig python:3.6+
USE_PYTHON=	distutils autoplist

CXXFLAGS+=	$(pkg-config --cflags ipopt)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cpython-*.so

do-test: # tests fail: https://gitlab.com/g-braeunlich/ipyopt/-/issues/6
	@cd ${WRKSRC} && pytest

.include <bsd.port.mk>
