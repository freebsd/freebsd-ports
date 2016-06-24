# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	socli
PORTVERSION=	1.3a
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Stack overflow command line interface

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=0:textproc/py-beautifulsoup4 \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests

USES=		python:3 zip
USE_PYTHON=	autoplist distutils
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//g}

NO_ARCH=	yes

.include <bsd.port.mk>
