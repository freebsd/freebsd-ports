# New ports collection makefile for:	py-selenium
# Date created:				6 November 2011
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	selenium
PORTVERSION=	2.13.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python bindings for Selenium

LICENSE=	ASL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rdflib>=3.1.0:${PORTSDIR}/textproc/py-rdflib

LATEST_LINK=	py-${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONS=	FIREFOX	"Install Firefox"	Off

.include <bsd.port.options.mk>

.if defined(WITH_FIREFOX)
USE_FIREFOX=	yes
.endif

.include <bsd.port.mk>
