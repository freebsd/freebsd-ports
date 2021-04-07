PORTNAME=	msoffcrypto-tool
PORTVERSION=	4.11.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python tool and library for decrypting MS Office files

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}olefile>=0.45:devel/py-olefile@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	concurrent distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
