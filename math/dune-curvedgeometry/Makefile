PORTNAME=	dune-curvedgeometry
DISTVERSION=	2.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: curved dune geometries by Lagrange parameterization
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	dune-geometry>0:math/dune-geometry
RUN_DEPENDS=	dune-geometry>0:math/dune-geometry

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	f86747b5f5a4432dc587ca1cb0c6dfe72133b2ca

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+= DUNE_CURVEDGEOMETRY_CMAKE_HASH=8aada92d6d85497847b9b435863d1132

.include <bsd.port.mk>
