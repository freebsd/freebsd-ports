PORTNAME=	dune-spgrid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: A structured, parallel DUNE grid implementation
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DUNE_DEPENDS=	dune-common>0:math/dune-common \
		dune-grid>0:math/dune-grid \
		dune-geometry>0:math/dune-geometry \
		dune-uggrid>0:math/dune-uggrid
BUILD_DEPENDS=	${DUNE_DEPENDS} \
		openmpi>0:net/openmpi \
		vc>0:devel/vc
RUN_DEPENDS=	${DUNE_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	0e5a3b234d885ac566c9622421ab4eab97c8a50e

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
