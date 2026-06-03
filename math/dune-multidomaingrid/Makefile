PORTNAME=	dune-multidomaingrid
DISTVERSION=	2.10.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: meta grid for subdomains spanning parts of host grid
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2+

HPP_DEPENDS=	dune-common>0:math/dune-common \
		dune-geometry>0:math/dune-geometry \
		dune-grid>0:math/dune-grid \
		dune-typetree>0:math/dune-typetree
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	70ebbf54d6d608b6ad6e4949af3ff13f7e1c23ac

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+=	DUNE_MULTIDOMAINGRID_CMAKE_HASH=9a43d6b0cce18104cd3067dbdddf2b1c

.include <bsd.port.mk>
