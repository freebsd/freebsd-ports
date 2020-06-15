# Created by: Ralf van der Enden <tremere@cainites.net>
# $FreeBSD$

PORTNAME=	sabyenc3
PORTVERSION=	4.0.2
CATEGORIES=	news python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python yEnc package optimized for use within SABnzbd

LICENSE=	LGPL3

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sabyenc3.so

.include <bsd.port.mk>
