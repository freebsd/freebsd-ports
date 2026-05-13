PORTNAME=	dune-common
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	math


MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Build system, infrastructure and foundation classes
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	metis>0:math/metis \
		openmpi>0:net/openmpi \
		vc>0:devel/vc # Metis isn't used, see https://gitlab.dune-project.org/core/dune-common/-/issues/306
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++17-lang fortran pkgconfig python shebangfix
SHEBANG_FILES=	bin/dune-add-spdx bin/dune-ctest bin/dunepackaging.py cmake/scripts/extract_cmake_data.py
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS
CMAKE_ARGS=	-DTBB_INCLUDE_DIR=${LOCALBASE}/include -DTBB_LIBRARIES=${LOCALBASE}/lib/libtbb.so

PLIST_SUB+=	DUNE_COMMON_CMAKE_HASH=09f6943203612a8f3df596107fdd4f98

OPTIONS_DEFINE=	DOCS DOXYGEN MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	FREEBSD_INSTALL_DOXYGEN
DOXYGEN_IMPLIES=	DOCS

MANPAGES_CMAKE_BOOL=	FREEBSD_INSTALL_MANPAGES

PORTDOCS=	*

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/scripts/run-in-dune-env.sh.in
	@${RM} ${STAGEDIR}${PREFIX}/share/dune/cmake/scripts/set-dune-pythonpath.sh.in

.include <bsd.port.mk>
