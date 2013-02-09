# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grequests
PORTVERSION=	0.1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pythons Requests + Gevent

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
