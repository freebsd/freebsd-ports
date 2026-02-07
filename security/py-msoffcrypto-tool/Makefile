PORTNAME=	msoffcrypto-tool
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python tool and library for decrypting MS Office files
WWW=		https://github.com/nolze/msoffcrypto-tool

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}olefile>=0.45:devel/py-olefile@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
