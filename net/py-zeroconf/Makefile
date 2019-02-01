# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

PORTNAME=	zeroconf
PORTVERSION=	0.21.3
PORTREVISION=	2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pure python implementation of multicast DNS service discovery

LICENSE=	LGPL21+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>=0.1.6:net/py-ifaddr@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	jstasiak
GH_PROJECT=	python-zeroconf

NO_ARCH=	yes

.include <bsd.port.mk>
