# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rainbowstream
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Smart and nice Twitter client on terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arrow>0:devel/py-arrow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.3:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfiglet>0:misc/py-pyfiglet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twitter-tools>0:net/py-twitter-tools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${FLAVOR}

# Actually 2.7,3.2-
USES=		python:2.7
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
