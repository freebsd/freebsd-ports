# $FreeBSD$

PORTNAME=	dune-common
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Build system, infrastructure and foundation classes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		vc>0:devel/vc
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++17-lang fortran pkgconfig python shebangfix
SHEBANG_FILES=	bin/dune-ctest
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_COMMIT=	c5321673af09725a411bdd81aa2be5cfaf8bf9a6

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			latex:print/tex-formats \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

post-stage-DOCS-on: # https://gitlab.dune-project.org/core/dune-common/issues/191
	@${RMDIR} ${STAGEDIR}${DOCSDIR}/comm

.include <bsd.port.mk>
