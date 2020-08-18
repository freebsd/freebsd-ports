# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	python-igraph
PORTVERSION=	0.8.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High performance graph data structures and algorithms

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libigraph.so:math/igraph \
		aclocal:devel/automake
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}texttable>=1.6.2:textproc/py-texttable@${PY_FLAVOR}

USES=		bison gnome libtool:build python
USE_PYTHON=	autoplist concurrent distutils
USE_GNOME=	libxml2

pre-configure:
	@${ECHO} ${PORTVERSION} > ${WRKSRC}/vendor/source/igraph/IGRAPH_VERSION

.include <bsd.port.mk>
