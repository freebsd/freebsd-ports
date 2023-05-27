PORTNAME=	croniter
PORTVERSION=	0.3.20
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Iteration support for datetime objects with cron like format
WWW=		https://pypi.org/project/croniter/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
