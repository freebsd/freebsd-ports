PORTNAME=	requests-cache
PORTVERSION=	1.1.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	requests_cache-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistent cache for python requests
WWW=		https://requests-cache.readthedocs.io/en/stable/ \
		https://github.com/requests-cache/requests-cache

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=21.2:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=22.2:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.5:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}url-normalize>=1.4:net/py-url-normalize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.5,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
