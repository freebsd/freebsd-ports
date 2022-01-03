PORTNAME=	kliff
DISTVERSION=	0.3.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KIM-based Learning-Integrated Fitting Framework

LICENSE=	CDDL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>0:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

do-test: # tests fail with ImportErrors, complete list is unclear, see https://github.com/mjwen/kliff/issues/11
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
