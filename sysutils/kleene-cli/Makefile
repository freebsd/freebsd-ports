PORTNAME=	kleene-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
DISTVERSIONSUFFIX=	-rc.4
CATEGORIES=	sysutils

MAINTAINER=	lasse@philomath.dk
COMMENT=	Klee, the Kleene CLI client for managing containers on FreeBSD
WWW=		https://kleene.dev/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.9.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=23.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0_1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.9.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=12.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	kleene-project
GH_PROJECT=	klee
USE_PYTHON=	autoplist pep517

SUB_FILES=	pkg-message

.include <bsd.port.mk>
