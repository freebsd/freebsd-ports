PORTNAME=	dune-foamgrid
DISTVERSION=	g20210703
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: one- and two-dimensional simplex grids

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
GL_COMMIT=	43bfdb6181fae187fd803eca935a030d8d5ab0bc

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
