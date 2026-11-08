PORTNAME=	rpy2-rinterface
PORTVERSION=	3.6.7
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rpy2_rinterface-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-level interface from Python to the R
WWW=		https://rpy2.github.io/ \
		https://github.com/rpy2/rpy2/tree/master/rpy2-rinterface \
		https://github.com/rpy2/rpy2

LICENSE=	GPLv2+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.15.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libR.so:math/R
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.15.0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	RPY2_CFFI_MODE=ANY

OPTIONS_DEFINE=	NUMPY
OPTIONS_DEFAULT=NUMPY
NUMPY__DESC=	Numpy support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
