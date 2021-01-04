# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	python-igraph
PORTVERSION=	0.8.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High performance graph data structures and algorithms

LICENSE=	GPLv2

LIB_DEPENDS=	libigraph.so:math/igraph
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}texttable>=1.6.2:textproc/py-texttable@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cairocffi>0:graphics/py-cairocffi@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		bison gnome pkgconfig python:3.6+
USE_PYTHON=	distutils
USE_GNOME=	libxml2
PYDISTUTILS_BUILDARGS=	--use-pkg-config
PYDISTUTILS_INSTALLARGS=${PYDISTUTILS_BUILDARGS}

pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		${WRKSRC}/src/igraph/configuration.py

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
