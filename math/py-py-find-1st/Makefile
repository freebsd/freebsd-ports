PORTNAME=	py-find-1st
DISTVERSION=	1.1.6
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numpy extension module for efficient search in numpy arrays
WWW=		https://github.com/roebel/py_find_1st

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests are broken, see https://github.com/roebel/py_find_1st/issues/13

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/utils_find_1st/find_1st${PYTHON_TAG}.so

.include <bsd.port.mk>
