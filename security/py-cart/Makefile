PORTNAME=	cart
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CaRT Neutering format
WWW=		https://github.com/CybercentreCanada/cart

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent distutils unittest

USE_GITHUB=	yes
GH_ACCOUNT=	CybercentreCanada

# tests as of 1.2.3: 11 passed, 0 failed (8.309s)

.include <bsd.port.mk>
