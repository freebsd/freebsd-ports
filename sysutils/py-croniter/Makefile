PORTNAME=	croniter
PORTVERSION=	0.3.20
PORTREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Iteration support for datetime objects with cron like format
WWW=		https://pypi.org/project/croniter/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=1.5:devel/py-python-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
