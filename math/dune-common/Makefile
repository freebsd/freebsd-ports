PORTNAME=	dune-common
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Build system, infrastructure and foundation classes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		vc>0:devel/vc
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++17-lang fortran pkgconfig python shebangfix
SHEBANG_FILES=	bin/dune-ctest bin/setup-dunepy.py bin/dunepackaging.py bin/rmgenerated.py  cmake/scripts/extract_cmake_data.py
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_COMMIT=	df65b1282ea89ad40d2cb6565983f7e633ccce31

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	latex:print/tex-formats \
			sphinx-build:textproc/py-sphinx

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS

PORTDOCS=	*

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/scripts/run-in-dune-env.sh.in # https://gitlab.dune-project.org/core/dune-common/-/issues/229

.include <bsd.port.mk>
