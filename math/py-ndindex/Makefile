PORTNAME=	ndindex
PORTVERSION=	1.10.1
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://github.com/Quansight-Labs/ndindex/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for manipulating indices of ndarrays
WWW=		https://quansight-labs.github.io/ndindex/ \
		https://github.com/Quansight-Labs/ndindex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

OPTIONS_DEFINE=	ARRAYS
ARRAYS_DESC=	Array support

ARRAYS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
