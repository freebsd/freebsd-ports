PORTNAME=	focker
DISTVERSION=	0.93-g20200628
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	FreeBSD image orchestration tool in the vein of Docker

LICENSE=	GPLv3
#LICENSE_FILE=	Not packaged in PyPI sdist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jailconf>0:sysutils/py-jailconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes # tests and LICENSE_FILE not packaged in sdist
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	sadaszewski
GH_TAGNAME=	ce2108e3

NO_ARCH=	yes

# some tests assume `focker` is installed. Tests
# need refactor to test against WRKSRC build
do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
