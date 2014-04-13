# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	django-debug-toolbar
PORTVERSION=	1.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Configurable set of panels to display debug information

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}sqlparse>0:${PORTSDIR}/databases/py-sqlparse

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
