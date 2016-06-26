# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	socli
PORTVERSION=	1.7
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Stack overflow command line interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=0:textproc/py-beautifulsoup4 \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests

USES=		python:3
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	gautamkrishnar

NO_ARCH=	yes

.include <bsd.port.mk>
