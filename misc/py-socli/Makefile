# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	socli
PORTVERSION=	3.6
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Stack overflow command line interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}stackexchange>=0:devel/py-stackexchange \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	gautamkrishnar

NO_ARCH=	yes

.include <bsd.port.mk>
