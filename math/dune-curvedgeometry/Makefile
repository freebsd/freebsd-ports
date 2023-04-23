PORTNAME=	dune-curvedgeometry
DISTVERSION=	g20201116
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: curved dune geometries by Lagrange parameterization
WWW=		https://www.dune-project.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	dune-geometry>0:math/dune-geometry
RUN_DEPENDS=	dune-geometry>0:math/dune-geometry

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.mn.tu-dresden.de
GL_ACCOUNT=	iwr
GL_COMMIT=	fae02adf3757851f7f9caf41037da87caa52197d

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

PORTDOCS=	*

.include <bsd.port.mk>
