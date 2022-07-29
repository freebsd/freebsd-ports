PORTNAME=	PyMetis
DISTVERSION=	2022.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for the Metis graph partitioning software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
LIB_DEPENDS=	libmetis.so:math/metis
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++14-lang localbase python:3.6+
USE_PYTHON=	distutils autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pymetis/_internal.cpython-39.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest

.include <bsd.port.mk>
