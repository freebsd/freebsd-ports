# New ports collection makefile for:	pynzb
# Date created:		Wed Apr  7 13:06:51 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pynzb
PORTVERSION=	0.1.0
CATEGORIES=	news python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A unified API for parsing NZB files

LICENSE=	BSD

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

OPTIONS=	LXML		"Add support for py-lxml" Off \
		ELEMENTTREE	"Add support for py-elementtree" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LXML)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.1:${PORTSDIR}/devel/py-lxml
.endif

.if !defined(WITHOUT_ELEMENTTREE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

.include <bsd.port.post.mk>
