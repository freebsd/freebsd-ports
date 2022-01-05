PORTNAME=	fastapi
PORTVERSION=	0.70.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Python API Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic>0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
