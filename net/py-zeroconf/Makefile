# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

PORTNAME=	zeroconf
PORTVERSION=	0.19.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Pure python implementation of multicast DNS service discovery

LICENSE=	LGPL21+

BUILD_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.6:net/py-netifaces
RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.6:net/py-netifaces

USE_GITHUB=	yes
GH_ACCOUNT=	jstasiak
GH_PROJECT=	python-zeroconf

USES?=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
