PORTNAME=	elpa
DISTVERSION=	2026.02.001
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://elpa.mpcdf.mpg.de/software/tarball-archive/Releases/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Eigenvalue soLver for Petaflop Applications
WWW=		https://elpa.mpcdf.mpg.de/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING/lgpl.txt

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		compiler:c11 fortran gmake libtool localbase perl5 shebangfix
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-avx --disable-avx2 --disable-avx512 --disable-static \
		--disable-c-tests

CFLAGS+=	-I${WRKSRC} -I${WRKSRC}/private_modules
CFLAGS+=	-DFREEBSD_OSVERSION=${OSVERSION}
FCFLAGS+=	-I${WRKSRC} -I${WRKSRC}/private_modules
LDFLAGS+=	-lutil

# Build the private library first to ensure all .mod files exist before the public library is compiled
ALL_TARGET=	src/helpers/libelpa_private_la-mod_precision.lo \
		src/helpers/libelpa_private_la-mod_omp.lo \
		src/libelpa_private_la-elpa_generated_fortran_interfaces.lo \
		all
INSTALL_TARGET=	install-strip

BINARY_ALIAS=	make=gmake gcc=gcc${GCC_DEFAULT} g++=g++${GCC_DEFAULT} cpp=cpp${GCC_DEFAULT} # build fails with clang: recursively calls cc; cpp=GCC because fdep uses cpp for Fortran module tracking
FCFLAGS+=	-std=legacy -I${LOCALBASE}/include

MAKE_JOBS_UNSAFE=	yes # part of the workaround for .mod files

OPTIONS_DEFINE=			OPENMP MPI DOCS
OPTIONS_DEFINE_amd64=		SSE
OPTIONS_DEFAULT_amd64=		SSE

SSE_CFLAGS=			-msse3
OPENMP_CONFIGURE_ENABLE=	openmp
MPI_CONFIGURE_WITH=		mpi
MPI_LIB_DEPENDS=		libmpich.so:net/mpich \
				libscalapack.so:math/scalapack

PORTDOCS=	*

post-patch:
	# workaround for: https://github.com/marekandreas/elpa/issues/6
	@${FIND} ${WRKSRC} -name "*.mk" | ${XARGS} ${REINPLACE_CMD} -e 's|-Werror| |'
	# patch in the full path name of config-f90.h
	@${FIND} ${WRKSRC} -name *.F90 -o -name *.c | ${XARGS} ${REINPLACE_CMD} -e 's|#include "config-f90.h"|#include "${WRKSRC}/config-f90.h"|'
	# alloca.h is Linux-specific; alloca() is already provided by stdlib.h on FreeBSD
	@${FIND} ${WRKSRC} \( -name "*.c" -o -name "*.cpp" -o -name "*.cu" -o -name "*.hip" \) | \
		${XARGS} ${REINPLACE_CMD} -e 's|#include <alloca.h>||'

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:NSSE}
CONFIGURE_ARGS+=	--disable-sse --disable-sse-assembly
.endif

post-install-DOCS-on:
	@cd ${STAGEDIR}${DOCSDIR} && ${RM} *gpl* COPYING LICENSE

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
