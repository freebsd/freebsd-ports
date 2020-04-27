# $FreeBSD$

PORTNAME=	iso-639
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takefu@airport.fm
COMMENT=	Python library for ISO 639 standard

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}country>0:devel/py-country@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	noumar
GH_PROJECT=	iso639
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
		cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v tests/tests.py

.include <bsd.port.mk>
