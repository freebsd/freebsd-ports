# $FreeBSD$

PORTNAME=	dune-istl
DISTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Iterative Solver Template Library

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
GL_COMMIT=	761b28aa1deaa786ec55584ace99667545f1b493

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS PARMETIS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \

PARMETIS_DESC=		Install PerMetis # needed in headers, but license prohibits packaging
PARMETIS_BUILD_DEPENDS=	ParMetis>0:math/parmetis
PARMETIS_RUN_DEPENDS=	ParMetis>0:math/parmetis

PORTDOCS=	*

.include <bsd.port.mk>
