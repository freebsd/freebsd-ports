# $FreeBSD$

PORTNAME=	elpa
DISTVERSION=	2018.11.001
CATEGORIES=	math
MASTER_SITES=	http://elpa.mpcdf.mpg.de/html/Releases/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Eigenvalue soLver for Petaflop Applications

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING/lgpl.txt

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		fortran gmake libtool localbase perl5 shebangfix
SHEBANG_GLOB=	*.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avx --disable-avx2 --disable-static
USE_LDCONFIG=	yes

BINARY_ALIAS=	make=gmake gcc=gcc${GCC_DEFAULT} g++=g++${GCC_DEFAULT} # build fails with clang: recursively calls cc
FCFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=			OPENMP MPI DOCS
OPTIONS_DEFINE_amd64=		SSE
OPTIONS_DEFAULT_amd64=		SSE

SSE_CFLAGS=			-msse3
OPENMP_CONFIGURE_ENABLE=	openmp
MPI_CONFIGURE_WITH=		mpi
MPI_LIB_DEPENDS=		libmpich.so:net/mpich \
				libscalapack.so:math/scalapack

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:NSSE}
CONFIGURE_ARGS+=	--disable-sse --disable-sse-assembly
.endif

post-install-DOCS-on:
	@cd ${STAGEDIR}${DOCSDIR} && ${RM} *gpl* COPYING LICENSE

.include <bsd.port.mk>
