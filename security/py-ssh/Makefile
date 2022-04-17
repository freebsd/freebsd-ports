# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>

PORTNAME=	ssh
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python SSH2 protocol library

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.1:security/py-pycrypto@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
