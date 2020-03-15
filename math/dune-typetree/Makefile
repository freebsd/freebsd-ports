# $FreeBSD$

PORTNAME=	dune-typetree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0rc2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: The TypeTree library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune-common>0:math/dune-common \
		openmpi>0:net/openmpi \
		vc>0:devel/vc
RUN_DEPENDS=	dune-common>0:math/dune-common \
		openmpi>0:net/openmpi \
		vc>0:devel/vc

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	staging
GL_COMMIT=	b6427163a5ef45996471edad672ecab584aa490c

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

.include <bsd.port.mk>
