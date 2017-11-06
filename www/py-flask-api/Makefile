# $FreeBSD$

PORTNAME=	flask-api
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daniel@blodan.se
COMMENT=	Browsable Web APIs for Flask

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0.10.1:www/py-flask

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes

.include <bsd.port.mk>
