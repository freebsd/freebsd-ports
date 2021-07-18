PORTNAME=	mpich
PORTVERSION=	3.4.2
PORTREVISION=	2
CATEGORIES=	net parallel
MASTER_SITES=	https://www.mpich.org/static/downloads/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable implementation of MPI-1, MPI-2 and MPI-3

LICENSE=	MPICH
LICENSE_NAME=	MPICH
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# Unfortunately mpicc is BROKEN with sh (Bad substitution on arrays)
BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libhwloc.so:devel/hwloc2	\
		libjson-c.so:devel/json-c	\
		libfabric.so:net/libfabric	\
		libslurm.so:sysutils/slurm-wlm	\
		libepoll-shim.so:devel/libepoll-shim
RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	lam-7.* mpd-[0-9]* mpiexec-0.* mpich2-[0-9]*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c11 libtool perl5 pkgconfig
USE_LDCONFIG=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS FORTRAN L0
OPTIONS_GROUP=		PM
OPTIONS_GROUP_PM=	GFORKER HYDRA
OPTIONS_RADIO=		DEFAULTPM
OPTIONS_RADIO_DEFAULTPM=DGFORKER DHYDRA
OPTIONS_DEFAULT=	FORTRAN GFORKER HYDRA DHYDRA L0
OPTIONS_SUB=		yes

FORTRAN_USES=			fortran
FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_CONFIGURE_ON=		\
	MPICH_MPICC_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPICXX_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIF77_LDFLAGS="${MPICH_LDFLAGS}" \
	MPICH_MPIFORT_LDFLAGS="${MPICH_LDFLAGS}"
MPICH_LDFLAGS=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER} -B${LOCALBASE}/bin

PM_DESC=	Process managers
GFORKER_DESC=	Simple local process manager
HYDRA_DESC=	Parallel process manager
DEFAULTPM_DESC=	Default process manager
DGFORKER_DESC=	Make gforker the default process manager
DHYDRA_DESC=	Make hydra the default process manager

L0_DESC=		oneAPI Level Zero support
L0_LIB_DEPENDS=		libze_loader.so:devel/level-zero
L0_CPPFLAGS=		-DZE_IPC_MEMORY_FLAG_TBD=ZE_IPC_MEMORY_FLAG_BIAS_CACHED # 1.4.1
L0_CONFIGURE_ENV_OFF=	ac_cv_header_level_zero_ze_api_h=no \
			ac_cv_lib_ze_loader_zeInit=no

CONFIGURE_ARGS=	--enable-fast="" --with-hwloc-prefix=${LOCALBASE} \
		--with-libfabric=${LOCALBASE} \
		pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		MPICHLIB_CFLAGS="${CFLAGS}" \
		CFLAGS="-I${LOCALBASE}/include/json-c" \
		MPICHLIB_CPPFLAGS="${CPPFLAGS}" CPPFLAGS="" \
		MPICHLIB_CXXFLAGS="${CXXFLAGS}" CXXFLAGS="" \
		MPICHLIB_FFLAGS="${FFLAGS}" FFLAGS="" \
		MPICHLIB_FCFLAGS="${FCFLAGS}" FCFLAGS="" \
		MPICHLIB_LDFLAGS="${LDFLAGS}" LDFLAGS="" \
		MPICHLIB_LIBS="${LIBS}" \
		LIBS="-L${LOCALBASE}/lib -lepoll-shim -ljson-c -lm"	\
		BASH_SHELL=${LOCALBASE}/bin/bash

CFLAGS_powerpc64=	-D__BIG_ENDIAN

.include <bsd.port.options.mk>

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

post-patch:
	${RM} -r ${WRKSRC}/www

.include <bsd.port.mk>
