PORTNAME=	codecarbon
DISTVERSION=	2.3.5
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Track Compute emissions, recommend ways to reduce environmental impact
WWW=		https://mlco2.github.io/codecarbon/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo>0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynvml>0:devel/py-pynvml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>0:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # some test dependencies are missing

NO_ARCH=	yes

.include <bsd.port.mk>
