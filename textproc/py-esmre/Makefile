# $FreeBSD$

PORTNAME=	esmre
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Regular expression accelerator in Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so" -and -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
