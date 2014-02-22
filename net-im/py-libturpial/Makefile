# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libturpial
PORTVERSION=	1.6.0
CATEGORIES=	net-im python
MASTER_SITES=	http://files.turpial.org.ve/sources/stable/ \
	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twitter and Identi.ca API

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.3.1:${PORTSDIR}/devel/py-simplejson \
	${PYTHON_PKGNAMEPREFIX}oauth>=1.0.1:${PORTSDIR}/net/py-oauth \
	${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:${PORTSDIR}/www/py-requests

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
