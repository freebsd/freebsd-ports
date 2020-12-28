# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	python-gnupg
PORTVERSION=	0.4.5
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Python wrapper for the GNU Privacy Guard (GPG or GnuPG)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=   ${PYTHON_PKGNAMEPREFIX}coverage>=0.15.2:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.6+

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

do-test:
	        @(cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} test_gnupg.py --no-doctests)
	        @(cd ${WRKSRC} && ${SETENV} coverage-${PYTHON_VER} run test_gnupg.py --no-doctests)

.include <bsd.port.mk>
