PORTNAME=	cachelib
PORTVERSION=	0.17.0
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Collection of cache libraries in the same API interface
WWW=		https://github.com/pallets-eco/cachelib/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flit-core>=2:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
