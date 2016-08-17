# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rainbowstream
PORTVERSION=	1.3.5
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Smart and nice Twitter client on terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}arrow>0:devel/py-arrow \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}pyfiglet>0:misc/py-pyfiglet \
		${PYTHON_PKGNAMEPREFIX}twitter-tools>0:net/py-twitter-tools \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks

# Actually 2.7,3.2-3.4
USES=		python:2.7-3.4
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
