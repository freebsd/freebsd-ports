PORTNAME=	grimoire-elk
DISTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GrimoireELK processes and stores software development data to ElasticSearch
WWW=		https://github.com/chaoss/grimoirelab-elk

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}cereslib>=1.0.9:devel/py-cereslib@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}elasticsearch6>=6.3.1:textproc/py-elasticsearch6@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}elasticsearch-dsl6>=6.3.1:textproc/py-elasticsearch-dsl6@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}geopy>=2.0.0:net/py-geopy@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}graal>=1.1.2:devel/py-graal@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.9:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pandas>=0.22:math/py-pandas@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}perceval>=1.1.1:devel/py-perceval@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}perceval-mozilla>=1.0.11:devel/py-perceval-mozilla@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}perceval-opnfv>=1.0.11:devel/py-perceval-opnfv@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}perceval-puppet>=1.0.11:devel/py-perceval-puppet@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}perceval-weblate>=1.0.11:devel/py-perceval-weblate@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}sortinghat>=1.6.2:devel/py-sortinghat@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}statsmodels>=0.9.0:math/py-statsmodels@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}urllib3>=1.26:net/py-urllib3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
