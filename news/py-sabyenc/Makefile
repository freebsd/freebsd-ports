# Created by: Ralf van der Enden <tremere@cainites.net>
# $FreeBSD$

PORTNAME=	sabyenc
PORTVERSION=	3.3.1
CATEGORIES=	news python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tremere@cainites.net
COMMENT=	Python yEnc package optimized for use within SABnzbd

LICENSE=	LGPL3

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sabyenc.so

.include <bsd.port.mk>
