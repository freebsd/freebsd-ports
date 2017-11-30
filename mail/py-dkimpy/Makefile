# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	dkimpy
PORTVERSION=	0.6.1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Python library for DKIM email signing and verification

LICENSE=	ZLIB

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dns>=0:dns/py-dns@${FLAVOR}

NO_ARCH=	yes

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
