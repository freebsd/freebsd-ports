# $FreeBSD$

PORTNAME=	dune-metagrid
DISTVERSION=	g20180822
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: module implementing a variety of DUNE meta grids

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegrid.so:math/dune-grid

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_COMMIT=	5bc4c7e73bd76ccdaef842a5150c294095107a60

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
