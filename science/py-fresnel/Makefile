PORTNAME=	fresnel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.8
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Publication quality path tracing in real time
WWW=		https://github.com/glotzerlab/fresnel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libembree4.so:graphics/embree \
		libqhull_r.so:math/qhull \
		libtbb.so:devel/onetbb
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		cmake:testing compiler:c++14-lang python

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

GH_TUPLE=	glotzerlab:random123:7f2371b8c597a486cd33fb421a196d78efe08043:glotzerlab_random123/extern/random123 \
		glotzerlab:fresnel-examples:edae193:glotzerlab_fresnel_examples/doc/examples \
		glotzerlab:qhull:613debeaea72ee66626dace9ba1a2eff11b5d37d:glotzerlab_qhull/extern/qhull

do-test: install
	@cd ${WRKDIR} && ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
