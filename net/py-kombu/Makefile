# New ports collection makefile for:	kombu
# Date created:				18 March 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kombu
PORTVERSION=	2.0.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An AMQP messaging framework for Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqplib>=1.0:${PORTSDIR}/net/py-amqplib \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.1:${PORTSDIR}/devel/py-anyjson

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
