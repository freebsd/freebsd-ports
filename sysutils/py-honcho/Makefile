# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	honcho
PORTVERSION=	0.6.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Managing Procfile-based applications tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2

USE_GITHUB=	yes
GH_ACCOUNT=	nickstenning

USES=		python
USE_PYTHON=	autoplist distutils

regression-test:
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
