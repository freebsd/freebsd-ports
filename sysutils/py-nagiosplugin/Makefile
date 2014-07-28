# $FreeBSD$

PORTNAME=	nagiosplugin
PORTVERSION=	1.2.2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Class library for writing Nagios (Icinga) plugins

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

pre-install: regression-test

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
