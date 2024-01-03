PORTNAME=	mmcif
DISTVERSION=	0.84
CATEGORIES=	science biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	mmCIF Core Access Library
WWW=		https://mmcif.wwpdb.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		cmake:devel/cmake-core
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		bison python
USE_PYTHON=	distutils concurrent autoplist pytest # tests fail to run, see https://github.com/rcsb/py-mmcif/issues/18

.include <bsd.port.mk>
