# $FreeBSD$

PORTNAME=	googletrans
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Free Google Translate API that translates totally free of charge

LICENSE=	MIT
# LICENSE_FILE isn't packaged in the sdist, yet

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx==0.13.3:www/py-httpx@${PY_FLAVOR}

USES=		python:3.7+ # due www/py-httpx that requires 3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
