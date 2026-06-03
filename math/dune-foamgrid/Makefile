PORTNAME=	dune-foamgrid
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: one- and two-dimensional simplex grids
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2+

HPP_DEPENDS=	dune-common>0:math/dune-common \
		dune-geometry>0:math/dune-geometry \
		dune-grid>0:math/dune-grid
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	566e87f62bdef06b4762637d3e35ef05fc36cb0a

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_FOAMGRID_CMAKE_HASH=bf552a2d2ccafe4dc2389840b94eebfc

.include <bsd.port.mk>
