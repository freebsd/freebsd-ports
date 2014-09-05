# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyelasticsearch
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Flexible, high-scale API to elasticsearch

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0:${PORTSDIR}/www/py-requests

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
