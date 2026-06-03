PORTNAME=	dune-typetree
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: The TypeTree library
WWW=		https://www.dune-project.org/

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
GL_TAGNAME=	431458ffbcdb4507eb222c113f3bab569ee5c9f2

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

PORTDOCS=	*

PLIST_SUB+= DUNE_TYPETREE_CMAKE_HASH=7e64e74741afc1b4b6ace2cd5025d267

.include <bsd.port.mk>
