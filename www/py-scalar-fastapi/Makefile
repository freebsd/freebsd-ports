PORTNAME=	scalar-fastapi
PORTVERSION=	1.9.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scalar_fastapi-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Beautiful API reference for FastAPI
WWW=		https://github.com/scalar/scalar \
		https://scalar.com/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

.include <bsd.port.mk>
