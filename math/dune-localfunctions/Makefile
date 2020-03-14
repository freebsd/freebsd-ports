# $FreeBSD$

PORTNAME=	dune-localfunctions
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0rc2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Local finite elements

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune-common>0:math/dune-common \
		dune-geometry>0:math/dune-geometry \
		vc>0:devel/vc

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_ACCOUNT=	core
GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	core
GL_COMMIT=	4def7a7c627172d660854411d322818115a20765

CMAKE_ON=	BUILD_SHARED_LIBS

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	latex:print/tex-formats
DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build:textproc/py-sphinx

PORTDOCS=	*

post-stage-DOCS-on: # https://gitlab.dune-project.org/core/dune-common/issues/191
	@${RMDIR} ${STAGEDIR}${DOCSDIR}/comm

.include <bsd.port.mk>
