# $FreeBSD$

PORTNAME=	yarl
PORTVERSION=	0.10.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Yet another URL library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cython:lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}multidict>0:www/py-multidict

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
