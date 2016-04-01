# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_fabric
DISTVERSION=	1.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Ploy plugin for integration with Fabric

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}fabric>=1.4.0:devel/py-fabric

USES=		python:-2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
