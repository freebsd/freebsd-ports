# $FreeBSD$

PORTNAME=	parsel
PORTVERSION=	1.2.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Library to extract data from HTML and XML using XPath and CSS selectors

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.0.0:devel/py-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.9:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.2.4:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.8.0:www/py-w3lib

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
