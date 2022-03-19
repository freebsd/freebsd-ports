# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	igraph
DISTVERSION=	0.9.6
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package For Manipulating Undirected And Directed Graphs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libcxsparse.so:math/suitesparse-cxsparse \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libopenblas.so:math/openblas

USES=		bison cmake cpe gnome pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	git=false

pre-configure:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/IGRAPH_VERSION

.include <bsd.port.pre.mk>
.if (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300523) || \
	(${OSVERSION} >= 1200000 && ${OSVERSION} < 1203500)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-etc_cmake_compilers.cmake
.endif

.include <bsd.port.post.mk>
