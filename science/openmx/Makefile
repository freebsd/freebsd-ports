PORTNAME=	openmx
DISTVERSION=	3.9.9 # the 18June12 patch upgrades 3.9 -> 3.9.9
CATEGORIES=	science
MASTER_SITES=	https://www.openmx-square.org/ \
		https://www.openmx-square.org/bugfixed/21Oct17/:patch
DISTFILES=	${PORTNAME}${DISTVERSION:R}${EXTRACT_SUFX} \
		patch${DISTVERSION}${EXTRACT_SUFX}:patch # this patch isn't a patch, but a set of file updates
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}${DISTVERSION:R}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nanoscale material simulations using density functional theories (DFT)
WWW=		https://www.openmx-square.org/

LICENSE=	GPLv2

BROKEN_i386=	undefined reference to `__atomic_load', see bug#229605 and https://reviews.llvm.org/D42154

LIB_DEPENDS=	libblas.so:math/blas \
		libcblas.so:math/cblas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libscalapack.so:math/scalapack

USES=		dos2unix fortran gmake localbase:ldflags
USE_CXXSTD=	c++11

DOS2UNIX_FILES=	openmx_common.h

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION:R}

CFLAGS+=	-Dkcomp -fcommon
LDFLAGS+=	-lmpifort
FFLAGS+=	-fallow-argument-mismatch

WRKSRC_SUBDIR=	source

MAKE_ENV=	MPICH_CC=${CC}

BINARY_ALIAS=	gcc=${CXX}

UTIL_PROGS=	DosMain jx analysis_example esp polB bandgnu13 bin2txt cube2xsf intensity_map md2axsf

PLIST_FILES=	bin/${PORTNAME} ${UTIL_PROGS:C/^/bin\//}

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=		-msse -msse2 -mfpmath=sse
SIMD_CFLAGS_OFF=	-Dnosse
CFLAGS+=		${ARCH:S/amd64//:S/i386//:S/${ARCH}/-Dnosse/}

MAKE_JOBS_UNSAFE=	yes

pre-patch: # overlay files before patching
	@cd ${WRKSRC} && \
		${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/patch${DISTVERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && \
		${ECHO} "const char DFT_DATA_PATH[YOUSO10] = \"${DATADIR}/DFT_DATA19\";" >> ${WRKSRC}/Input_std.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for u in ${UTIL_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${u} ${STAGEDIR}${PREFIX}/bin
.endfor
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} DFT_DATA19 ${STAGEDIR}${DATADIR}
	# autoplist for potentials: about 500 files in DATADIR
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR:S/^${PREFIX}\///} -type f >> ${TMPPLIST}

.include <bsd.port.mk>
