# New ports collection makefile for:	py-eventlet
# Date created:		2010-07-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	eventlet
PORTVERSION=	0.9.16
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Concurrent networking library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0:${PORTSDIR}/devel/py-greenlet

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
