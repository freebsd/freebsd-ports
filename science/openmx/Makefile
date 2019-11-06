# $FreeBSD$

PORTNAME=	openmx
DISTVERSION=	3.8.5 # the 18June12 patch upgrades 3.8 -> 3.8.5
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://www.openmx-square.org/ \
		http://www.openmx-square.org/bugfixed/18June12/:patch
DISTFILES=	${PORTNAME}${DISTVERSION:R}${EXTRACT_SUFX} \
		patch${DISTVERSION}${EXTRACT_SUFX}:patch # this patch isn't a patch, but a set of file updates
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}${DISTVERSION:R}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nanoscale material simulations using density functional theories (DFT)

BROKEN=		unfetchable

LICENSE=	GPLv2

BROKEN_i386=	undefined reference to `__atomic_load', see bug#229605 and https://reviews.llvm.org/D42154
DEPRECATED=	Depends on expiring devel/openmp
EXPIRATION_DATE=	2019-12-31

LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libiomp5.so:devel/openmp

USES=		dos2unix fortran gmake localbase:ldflags
DOS2UNIX_FILES=	openmx_common.h
USE_CXXSTD=	c++11
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION:R}

CFLAGS+=	-Dkcomp
LDFLAGS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${LOCALBASE}/lib/libmpifort.so

WRKSRC_SUBDIR=	source

MAKE_ENV=	MPICH_CC=${CC}
MAKE_ARGS+=	CFLAGS="${CFLAGS}" FFLAGS="${FFLAGS}" LDFLAGS="${LDFLAGS}" GCC_LIB=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgfortran.so

BINARY_ALIAS=	gcc=${CXX} gcc7=${CXX}

UTIL_PROGS=	DosMain jx analysis_example esp polB bandgnu13 bin2txt cube2xsf intensity_map md2axsf

PLIST_FILES=	bin/${PORTNAME} ${UTIL_PROGS:C/^/bin\//}

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=		-msse -msse2 -mfpmath=sse
SIMD_CFLAGS_OFF=	-Dnosse
CFLAGS+=		${ARCH:S/amd64//:S/i386//:S/${ARCH}/-Dnosse/}

pre-patch: # overlay files before patching
	@cd ${WRKSRC} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/patch${DISTVERSION}${EXTRACT_SUFX}

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} 's|DFT_DATA_PATH|"${DATADIR}/DFT_DATA13"|' Input_std.c check_lead.c SetPara_DFT.c OutData.c OutData_Binary.c

post-install:
.for u in ${UTIL_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${u} ${STAGEDIR}${PREFIX}/bin
.endfor
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} DFT_DATA13 ${STAGEDIR}${DATADIR}
	# autoplist for potentials: about 500 files in DATADIR
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR:S/^${PREFIX}\///} -type f >> ${TMPPLIST}

.include <bsd.port.mk>
