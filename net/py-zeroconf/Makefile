PORTNAME=	zeroconf
PORTVERSION=	0.39.4
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pure python implementation of multicast DNS service discovery
WWW=		https://github.com/jstasiak/python-zeroconf

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ifaddr>=0.1.7:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=3.0.1:devel/py-async_timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	jstasiak
GH_PROJECT=	python-zeroconf

NO_ARCH=	yes
TEST_TARGET=	test

pre-test:
	${REINPLACE_CMD} -e 's|nosetests|nosetests-${PYTHON_VER} --exclude=test_lots_of_names|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
