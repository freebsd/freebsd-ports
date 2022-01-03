# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	igraph
PORTVERSION=	0.9.5
CATEGORIES=	math

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libcxsparse.so:math/suitesparse-cxsparse \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libopenblas.so:math/openblas

USES=		bison cmake cpe gnome libtool pathfix
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	git=false

pre-configure:
	@${ECHO} ${PORTVERSION} > ${WRKSRC}/IGRAPH_VERSION

.include <bsd.port.mk>
