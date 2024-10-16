PORTNAME=	grimoirelab
DISTVERSION=	1.7.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool set for software development analytics
WWW=		https://chaoss.github.io/grimoirelab/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}cereslib>=1.0.5:devel/py-cereslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graal>=1.0.7:devel/py-graal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoire-elk>=1.2.0:textproc/py-grimoire-elk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-panels>=1.1.1:textproc/py-grimoirelab-panels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.5:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kidash>=1.0.6:textproc/py-kidash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=1.0.7:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-mozilla>=1.0.7:devel/py-perceval-mozilla@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-opnfv>=1.0.7:devel/py-perceval-opnfv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-puppet>=1.0.7:devel/py-perceval-puppet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-weblate>=1.0.7:devel/py-perceval-weblate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sirmordred>=1.1.1:devel/py-sirmordred@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortinghat>=1.4.0:devel/py-sortinghat@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_GLOB=	*.py

BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

.include <bsd.port.mk>
