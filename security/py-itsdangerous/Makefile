# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	itsdangerous
PORTVERSION=	0.23
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Various helpers to pass data in untrusted environments

LICENSE=	BSD3CLAUSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	JSON

JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.0:${PORTSDIR}/devel/py-simplejson

.include <bsd.port.mk>
