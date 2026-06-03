PORTNAME=	dune-localfunctions
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: Local finite elements
WWW=		https://www.dune-project.org/

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
GL_TAGNAME=	56e0e0e97bcd1cadeb05296e89a492900c0fd790

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+=	DUNE_LOCALFUNCTIONS_CMAKE_HASH=49d120d3897aee42c5e8eb22158d11e8

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

post-stage-DOCS-on: # https://gitlab.dune-project.org/core/dune-common/issues/191
	@${RMDIR} ${STAGEDIR}${DOCSDIR}/comm || ${TRUE}

.include <bsd.port.mk>
