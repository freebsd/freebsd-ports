# $FreeBSD$

PORTNAME=	nagiosplugin
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Class library for writing Nagios (Icinga) plugins

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
