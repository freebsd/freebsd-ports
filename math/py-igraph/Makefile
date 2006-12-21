# New ports collection makefile for:	py-igraph
# Date created:		2006-12-20
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	igraph
PORTVERSION=	0.3.2
CATEGORIES=	math python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/i/igraph/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	High performance graph data structures and algorithms

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
