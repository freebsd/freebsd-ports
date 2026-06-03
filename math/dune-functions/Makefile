PORTNAME=	dune-functions
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Abstraction layer for global finite element functions
WWW=		https://www.dune-project.org/

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
GL_TAGNAME=	fdb0700d3b6c47dd3befedd2591ef42e6da4dd78

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_FUNCTIONS_CMAKE_HASH=427fda8e30996bbd714a6fdf3f51fcbb

.include <bsd.port.mk>
