# New ports collection makefile for:	pebrot
# Date created:		26 March 2004
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pebrot
PORTVERSION=	0.8.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Text-based MSN messenger client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cjkcodecs/__init__.py:${PORTSDIR}/converters/py-cjkcodecs

USE_PYTHON=	2.1+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
