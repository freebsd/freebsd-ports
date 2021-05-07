PORTNAME=	googletrans
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Free Google Translate API that translates totally free of charge

LICENSE=	MIT
# LICENSE_FILE isn't packaged in the sdist, yet

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx013>=0.13.3<0.13.4:www/py-httpx013@${PY_FLAVOR}

USES=		python:3.7+ # due www/py-httpx that requires 3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
