PORTNAME=	openmpi
DISTVERSION=	5.0.5
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v${PORTVERSION:R}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	High Performance Message Passing Library
WWW=		https://www.open-mpi.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Not supported on 32-bits - see net/openmpi4

LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libevent.so:devel/libevent \
		libmunge.so:security/munge

# :keepla because port uses lt_dlopen
USES=		compiler:c11 fortran gmake libtool:keepla localbase perl5 \
		pkgconfig python:build shebangfix tar:bzip2
USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib
USE_PERL5=	build
SHEBANG_FILES=	ompi/mca/common/monitoring/profile2mat.pl \
		ompi/mca/common/monitoring/aggregate_profile.pl

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PKGBASE}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${MPIDIR}
GNU_CONFIGURE_MANPREFIX=${PREFIX}/${MPIDIR}/share
CONFIGURE_ARGS+=	--program-prefix= \
			--with-hwloc=external \
			--without-ofi \
			--enable-mpi-fortran=usempif08 \
			--with-libevent=external \
			--enable-mca-no-build=verbs,btl_openib,oob_ud \
			--with-wrapper-ldflags=-Wl,-rpath=-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
TEST_TARGET=		check
CFLAGS+=		${CFLAGS_F2018}
CONFLICTS_INSTALL=	openmpi4-4*

DOCSDIR=	${PREFIX}/${MPIDIR}/share/doc
MANDIRS=	${PREFIX}/${MPIDIR}/share/man
BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_SUB+=	MPIDIR=${MPIDIR}
PORTDOCS=	*

OPTIONS_DEFINE=			AVX DEBUG DOCS IPV6 ROMIO SLURM
OPTIONS_DEFAULT=		ROMIO
OPTIONS_EXCLUDE_aarch64=	AVX
OPTIONS_EXCLUDE_armv6=		AVX SLURM
OPTIONS_EXCLUDE_armv7=		AVX SLURM
OPTIONS_EXCLUDE_i386=		SLURM
OPTIONS_EXCLUDE_mips=		AVX SLURM
OPTIONS_EXCLUDE_mips64=		AVX
OPTIONS_EXCLUDE_powerpc=	AVX SLURM
OPTIONS_EXCLUDE_powerpc64=	AVX
OPTIONS_EXCLUDE_powerpc64le=	AVX
OPTIONS_EXCLUDE_riscv64=	AVX
OPTIONS_SUB=			yes

AVX_DESC=	Enable AVX instructions
ROMIO_DESC=	Enable romio mpi-io support
SLURM_DESC=	Enable SLURM support

AVX_CONFIGURE_OFF=	--enable-mca-no-build=op-avx

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}recommonmark>0:textproc/py-recommonmark@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

IPV6_CONFIGURE_ENABLE=	ipv6

ROMIO_CONFIGURE_OFF=	--disable-io-romio

SLURM_LIB_DEPENDS=	libslurm.so:sysutils/slurm-wlm
SLURM_CONFIGURE_WITH=	slurm

.include <bsd.port.pre.mk>

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch
.endif

# Both clang and gcc support half precision on these platforms
# Note: RISC-V can support half precision with Zhf extension
.if ${ARCH:Maarch64} || ${ARCH:Mamd64}
PLIST_SUB+=	SHORTFLOAT=""
.else
PLIST_SUB+=	SHORTFLOAT="@comment "
.endif

LIBDIR2FIX=	oshmem/tools/wrappers opal/tools/wrappers \
		3rd-party/openpmix ompi/tools/wrappers

pre-configure:
.for d in ${LIBDIR2FIX}
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${LOCALBASE}/libdata/pkgconfig|g' \
		${WRKSRC}/${d}/Makefile.in
.endfor

.include <bsd.port.post.mk>
