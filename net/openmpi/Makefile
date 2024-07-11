PORTNAME=	openmpi
PORTVERSION=	5.0.3
PORTREVISION=	2
CATEGORIES=	net parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v${PORTVERSION:R}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	High Performance Message Passing Library
WWW=		https://www.open-mpi.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Not supported on 32-bits - see net/openmpi4

LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libevent.so:devel/libevent \
		libmunge.so:security/munge \
		libze_loader.so:devel/level-zero

# :keepla because port uses lt_dlopen
USES=		compiler:c11 fortran gmake libtool:keepla localbase perl5 \
		pkgconfig python:build shebangfix tar:bzip2

CONFLICTS_INSTALL=	openmpi4-4*

BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_PERL5=	build

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PKGBASE}

PLIST_SUB+=	MPIDIR=${MPIDIR}

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
CFLAGS+=	${CFLAGS_F2018}

# See <https://github.com/open-mpi/ompi/issues/9715>
CONFIGURE_ARGS+=	--disable-io-romio

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib

TEST_TARGET=	check

MANDIRS=	${PREFIX}/${MPIDIR}/share/man

SHEBANG_FILES=	ompi/mca/common/monitoring/profile2mat.pl \
		ompi/mca/common/monitoring/aggregate_profile.pl

OPTIONS_DEFINE=			AVX DEBUG DOCS IPV6 SLURM
OPTIONS_DEFAULT=		SLURM
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
SLURM_DESC=	Enable SLURM support

AVX_CONFIGURE_OFF=	--enable-mca-no-build=op-avx

DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}recommonmark>0:textproc/py-recommonmark@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCSDIR=		${PREFIX}/${MPIDIR}/share/doc
PORTDOCS=		*

IPV6_CONFIGURE_ENABLE=	ipv6

SLURM_CONFIGURE_WITH=	slurm
SLURM_LIB_DEPENDS=	libslurm.so:sysutils/slurm-wlm

.include <bsd.port.pre.mk>

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch
.endif

.if ${ARCH} != aarch64 && ${ARCH} != amd64 && ${ARCH} != i386 && !${ARCH:Mpowerpc*}
PLIST_SUB+=	NO_MCA_PATCHER_OVERWRITE="@comment "
.else
PLIST_SUB+=	NO_MCA_PATCHER_OVERWRITE=""
.endif

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 170 && !${ARCH:Mpowerpc*}
PLIST_SUB+=	SHORTFLOAT=""
.else
PLIST_SUB+=	SHORTFLOAT="@comment "
.endif

LIBDIR2FIX=	oshmem/tools/wrappers opal/tools/wrappers	\
		3rd-party/openpmix ompi/tools/wrappers

pre-configure:
.for d in ${LIBDIR2FIX}
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${LOCALBASE}/libdata/pkgconfig|g'	\
		${WRKSRC}/${d}/Makefile.in
.endfor

.include <bsd.port.post.mk>
