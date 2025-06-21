PORTNAME=	mpich
DISTVERSION=	4.3.1
CATEGORIES=	net parallel
MASTER_SITES=	https://www.mpich.org/static/downloads/${DISTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Portable implementation of MPI-1, MPI-2 and MPI-3
WWW=		https://www.mpich.org/

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libhwloc.so:devel/hwloc2	\
		libjson-c.so:devel/json-c	\
		libfabric.so:net/libfabric	\
		libepoll-shim.so:devel/libepoll-shim

USES=		compiler:c11 libtool localbase perl5 pkgconfig python:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-fast="" \
		--with-libfabric=${LOCALBASE} \
		--with-libfabric-include=${WRKDIR}/include \
		--with-hwloc=${LOCALBASE} \
		pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		MPICHLIB_CFLAGS="${CFLAGS}" \
		CFLAGS="-I${LOCALBASE}/include/json-c ${CFLAGS_F2018}" \
		MPICHLIB_CPPFLAGS="${CPPFLAGS}" CPPFLAGS="" \
		MPICHLIB_CXXFLAGS="${CXXFLAGS}" CXXFLAGS="" \
		MPICHLIB_FFLAGS="${FFLAGS}" FFLAGS="" \
		MPICHLIB_FCFLAGS="${FCFLAGS}" FCFLAGS="" \
		MPICHLIB_LDFLAGS="${LDFLAGS}" LDFLAGS="" \
		MPICHLIB_LIBS="${LIBS}" \
		LIBS="-L${LOCALBASE}/lib -lepoll-shim -ljson-c -lm" \
		BASH_SHELL=${LOCALBASE}/bin/bash

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS=	mpd

BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS FORTRAN SLURM L0
OPTIONS_DEFAULT=	FORTRAN GFORKER HYDRA DHYDRA
OPTIONS_GROUP=		PM
OPTIONS_GROUP_PM=	GFORKER HYDRA
OPTIONS_RADIO=		DEFAULTPM
OPTIONS_RADIO_DEFAULTPM=DGFORKER DHYDRA
OPTIONS_SUB=		yes

DEFAULTPM_DESC=	Default process manager
DGFORKER_DESC=	Make gforker the default process manager
DHYDRA_DESC=	Make hydra the default process manager
GFORKER_DESC=	Simple local process manager
HYDRA_DESC=	Parallel process manager
L0_DESC=	oneAPI Level Zero support
PM_DESC=	Process managers
SLURM_DESC=	Extra Slurm support

MPICH_LDFLAGS=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER} -B${LOCALBASE}/bin
FORTRAN_USES=			fortran
FORTRAN_CONFIGURE_ON=		\
	MPICH_MPICC_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPICXX_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIF77_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIFORT_LDFLAGS="${MPICH_LDFLAGS}"
FORTRAN_CONFIGURE_ENABLE=	fortran
L0_LIB_DEPENDS=			libze_loader.so:devel/level-zero
L0_CONFIGURE_WITH=		ze
SLURM_IMPLIES=			HYDRA
SLURM_LIB_DEPENDS=		libslurm.so:sysutils/slurm-wlm
SLURM_CONFIGURE_WITH=		slurm

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:ML0}
# PR 278869 - level-zero is broken
IGNORE=	is currently not working with the L0 option. Unset L0
.endif

.if ${COMPILER_TYPE} == clang && (${COMPILER_VERSION} == 170 || ${COMPILER_VERSION} >= 181 && ${ARCH} == "i386")
# linker error when compiling with llvm 17.0.6 on CURRENT - PR 276035
# To be removed when all RELEASE and CURRENT no longer need it
# Error remains for i386 and llvm-181 on CURRENT
CONFIGURE_ENV+=	ac_cv_sizeof___float128=0
.endif

.for pm in ${OPTIONS_GROUP_PM}
. if ${PORT_OPTIONS:M${pm}}
.  if empty(PMLIST)
PMLIST=		${pm:tl}
.  elif ${PORT_OPTIONS:MD${pm}}
PMLIST:=	${pm:tl},${PMLIST}
.  else
PMLIST:=	${PMLIST},${pm:tl}
.  endif
. endif
.endfor

.if empty(PMLIST)
CONFIGURE_ARGS+=--without-pm
PLIST_SUB+=	EXEC="@comment " EXECGFORKER="@comment "
.else
CONFIGURE_ARGS+=--with-pm=${PMLIST}
PLIST_SUB+=	EXEC=""
.if ${PMLIST:M*,gforker*}
PLIST_SUB+=	EXECGFORKER=""
.else
PLIST_SUB+=	EXECGFORKER="@comment "
.endif
.endif

post-extract:
	${FIND} ${WRKSRC} -name "*.orig" -delete

post-patch:
# To avoid pollution from ${LOCALBASE}/include, set up the build to look in
# ${WRKDIR} for libfabric include/rdma/ header files (see --with-libfabric
# configure args).
# PR: 265684
	${MKDIR} ${WRKDIR}/include && ${LN} -s ${LOCALBASE}/include/rdma ${WRKDIR}/include/

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/mpixxx_opts.conf ${STAGEDIR}${PREFIX}/etc/mpixxx_opts.conf.sample

.include <bsd.port.post.mk>
