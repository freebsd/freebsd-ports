# $FreeBSD$

PORTNAME=	dune-functions
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0rc2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Abstraction layer for global finite element functions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DUNE_DEPENDS=	dune-common>0:math/dune-common \
		dune-geometry>0:math/dune-geometry \
		dune-grid>0:math/dune-grid \
		dune-istl>0:math/dune-istl \
		dune-localfunctions>0:math/dune-localfunctions \
		dune-typetree>0:math/dune-typetree
BUILD_DEPENDS=	${DUNE_DEPENDS} \
		vc>0:devel/vc
RUN_DEPENDS=	${DUNE_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	staging
GL_COMMIT=	715a380912eb6d14f06a4d758f4d1255bda25c95

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
