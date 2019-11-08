# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	igraph
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://igraph.org/nightly/get/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High performance graph data structures and algorithms

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libigraph.so:math/igraph

USES=		gnome python
USE_PYTHON=	autoplist concurrent distutils
USE_GNOME=	libxml2

.include <bsd.port.mk>
