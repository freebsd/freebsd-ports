# New ports collection makefile for:	GinGin
# Date created:		2008-02-26
# Whom:			Thinker K.F. Li <thinker@cowboy.branda.to>
#
# $FreeBSD$
#

PORTNAME=	GinGin
PORTVERSION=	0.9.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hybrid of WIKI and BLOG system

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mez_xml/__init__.py:${PORTSDIR}/devel/py-mez_xml
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mez_xml/__init__.py:${PORTSDIR}/devel/py-mez_xml

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
