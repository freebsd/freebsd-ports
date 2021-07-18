# Created by: John Hixson <jhixson@gmail.com>

PORTNAME=	zeroconf
PORTVERSION=	0.30.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pure python implementation of multicast DNS service discovery

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ifaddr>=0.1.7:net/py-ifaddr@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	jstasiak
GH_PROJECT=	python-zeroconf

NO_ARCH=	yes
TEST_TARGET=	test

pre-test:
	${REINPLACE_CMD} -e 's|nosetests|nosetests-${PYTHON_VER} --exclude=test_lots_of_names|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
