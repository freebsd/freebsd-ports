# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyquery
PORTVERSION=	1.2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A jquery-like library for python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:${PORTSDIR}/www/py-cssselect

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
