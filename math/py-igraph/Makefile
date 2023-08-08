PORTNAME=	igraph
DISTVERSION=	0.10.4
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High performance graph data structures and algorithms
WWW=		https://igraph.org/python/

LICENSE=	GPLv2

BUILD_DEPENDS=	cmake:devel/cmake-core
LIB_DEPENDS=	libigraph.so:math/igraph
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}texttable>=1.6.2:textproc/py-texttable@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cairocffi>0:graphics/py-cairocffi@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}

USES=		bison gnome pkgconfig python
USE_PYTHON=	distutils concurrent autoplist
USE_GNOME=	libxml2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/igraph/_igraph${PYTHON_EXT_SUFFIX}.so

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
