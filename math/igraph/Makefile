PORTNAME=	igraph
DISTVERSION=	0.10.12
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs
WWW=		https://igraph.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libcxsparse.so:math/suitesparse-cxsparse \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libopenblas.so:math/openblas

USES=		bison cmake cpe gnome pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Git:BOOL=True \
		-DFLEX_EXECUTABLE:FILEPATH=${LOCALBASE}/bin/flex

pre-configure:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/IGRAPH_VERSION

.include <bsd.port.mk>
