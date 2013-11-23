# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyelasticsearch
PORTVERSION=	0.6.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Flexible, high-scale API to elasticsearch

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYTHON_PY3K_PLIST_HACK=yes

.include <bsd.port.mk>
