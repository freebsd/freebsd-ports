PORTNAME=	sarpy
PORTVERSION=	1.3.61
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read, write and process complex SAR and other associated data
WWW=		https://github.com/ngageoint/sarpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=4.1.1:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=1.6.4:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL
ALL_DESC=	All optional dependencies

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2.5:math/py-networkx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytest>=3.3.2,1:devel/py-pytest@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}smart-open>=0:net/py-smart-open@${PY_FLAVOR}

.include <bsd.port.mk>
