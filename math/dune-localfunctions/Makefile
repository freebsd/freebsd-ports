# $FreeBSD$

PORTNAME=	dune-localfunctions
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0rc2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Local finite elements

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DUNE_DEPENDS=	dune-common>0:math/dune-common \
		dune-geometry>0:math/dune-geometry
BUILD_DEPENDS=	${DUNE_DEPENDS} \
		vc>0:devel/vc
RUN_DEPENDS=	${DUNE_DEPENDS}

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_COMMIT=	4def7a7c627172d660854411d322818115a20765

CMAKE_ON=	BUILD_SHARED_LIBS

NO_ARCH=	yes

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
