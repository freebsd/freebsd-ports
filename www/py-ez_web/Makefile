# New ports collection makefile for:	py-ez_web
# Date created:		2007-03-27
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	ez_web
PORTVERSION=	0.1
CATEGORIES=	www devel
MASTER_SITES=	http://master.branda.to/downloads/ez_web/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thinker@branda.to
COMMENT=	Ez_web is a tiny and designed for modify web framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ez_xml/__init__.py:${PORTSDIR}/devel/py-ez_xml

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
