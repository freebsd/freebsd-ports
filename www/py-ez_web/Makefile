# New ports collection makefile for:	py-ez_web
# Date created:		2007-03-27
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	ez_web
PORTVERSION=	0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://master.branda.to/downloads/ez_web/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny and designed for modification web framework

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ez_xml/__init__.py:${PORTSDIR}/devel/py-ez_xml

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
