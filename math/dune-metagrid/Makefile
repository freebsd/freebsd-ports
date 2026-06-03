PORTNAME=	dune-metagrid
DISTVERSION=	g20231219
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DUNE framework: module implementing a variety of DUNE meta grids
WWW=		https://www.dune-project.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdunealugrid.so:math/dune-alugrid \
		libdunecommon.so:math/dune-common \
		libdunegrid.so:math/dune-grid

USES=		cmake compiler:c++17-lang fortran pkgconfig
USE_GITLAB=	yes

GL_SITE=	https://gitlab.dune-project.org
GL_ACCOUNT=	extensions
GL_TAGNAME=	edd85ac1c29fd11b378ed4a65bdb1adccb0fc3f2

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

PORTDOCS=	*

CMAKE_OFF=	DUNE_ENABLE_PYTHONBINDINGS

PLIST_SUB+=	DUNE_METAGRID_CMAKE_HASH=b490fd31d39bb9996fd1c7d6d90d01ee

.include <bsd.port.mk>
