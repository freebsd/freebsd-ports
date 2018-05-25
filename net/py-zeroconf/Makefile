# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

PORTNAME=	zeroconf
PORTVERSION=	0.20.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Pure python implementation of multicast DNS service discovery

LICENSE=	LGPL21+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.6:net/py-netifaces@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	jstasiak
GH_PROJECT=	python-zeroconf

NO_ARCH=	yes

.include <bsd.port.mk>
