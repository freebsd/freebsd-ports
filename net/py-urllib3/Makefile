# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	urllib3
PORTVERSION=	1.6
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTP Python's standard library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.3.2:${PORTSDIR}/net/py-ndg_httpsclient

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
