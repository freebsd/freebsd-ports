PORTNAME=	googletrans
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Google Translate API that translates totally free of charge
WWW=		https://github.com/ssut/py-googletrans

LICENSE=	MIT
# LICENSE_FILE isn't packaged in the sdist, yet

DEPRECATED=	Umaintained for over 3 years, depends on old www/py-httpx013
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx013>=0.13.3<0.13.4:www/py-httpx013@${PY_FLAVOR}

USES=		python # due www/py-httpx that requires 3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
