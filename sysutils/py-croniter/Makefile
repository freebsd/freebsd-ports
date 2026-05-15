PORTNAME=	croniter
PORTVERSION=	6.2.2
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Iteration support for datetime objects with cron like format
WWW=		https://pypi.org/project/croniter/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.29.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=26.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=1.1.1:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.6.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2026.4.28.13:devel/py-trove-classifiers@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=1.5:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2021.1:devel/py-pytz@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

SHEBANG_FILES=	src/croniter/tests/*.py

.include <bsd.port.mk>
