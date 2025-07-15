PORTNAME=	igraph
DISTVERSION=	0.11.9
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python-igraph

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High performance graph data structures and algorithms
WWW=		https://igraph.org/python/

LICENSE=	GPLv2

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libblas.so:math/blas \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}texttable>=1.6.2:textproc/py-texttable@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cairocffi>0:graphics/py-cairocffi@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		bison gnome pkgconfig python
USE_PYTHON=	distutils concurrent autoplist
USE_GNOME=	libxml2

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${PATCH_WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/igraph/_igraph*.so

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
