PORTNAME=	dune-istl
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Iterative Solver Template Library
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

HPP_DEPENDS=	arpack++>0:math/arpack++ \
		dune-common>0:math/dune-common \
		suitesparse>0:math/suitesparse # needed in headers, but OPTIONAL dependency set is wider: https://gitlab.dune-project.org/core/dune-istl/-/issues/97
BUILD_DEPENDS=	${HPP_DEPENDS} \
		vc>0:devel/vc
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_TAGNAME=	2e4db0b47b7adae3b824d36709b947b867e730a6

NO_ARCH=	yes

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+=	DUNE_ISTL_CMAKE_HASH=fb00f9855333dc21fd1e00ed8438c9ac

OPTIONS_DEFINE=	DOCS PARMETIS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PARMETIS_DESC=		Install PerMetis # needed in headers, but license prohibits packaging
PARMETIS_BUILD_DEPENDS=	ParMetis>0:math/parmetis
PARMETIS_RUN_DEPENDS=	ParMetis>0:math/parmetis

PORTDOCS=	*

.include <bsd.port.mk>
