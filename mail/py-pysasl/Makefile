PORTNAME=	pysasl
DISTVERSION=	0.8.1
CATEGORIES=	mail security
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Pure Python SASL client and server library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		PASSLIB
OPTIONS_DEFAULT=	PASSLIB

PASSLIB_DESC=	Password hashing support

PASSLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR}

.include <bsd.port.mk>
