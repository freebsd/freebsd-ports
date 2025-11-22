PORTNAME=	openmpi
DISTVERSION=	4.1.8
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v${DISTVERSION:R}/
PKGNAMESUFFIX=	4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Performance Message Passing Library
WWW=		https://www.open-mpi.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libltdl.so:devel/libltdl \
		libevent.so:devel/libevent \
		libmunge.so:security/munge

# :keepla because port uses lt_dlopen
USES=		fortran gmake libtool:keepla localbase perl5 \
		pkgconfig shebangfix tar:bzip2
MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PORTNAME}
USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib
USE_PERL5=	build

SHEBANG_FILES=	ompi/mca/common/monitoring/profile2mat.pl \
		ompi/mca/common/monitoring/aggregate_profile.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/${MPIDIR}/share
GNU_CONFIGURE_PREFIX=	${PREFIX}/${MPIDIR}
CONFIGURE_ARGS+=	--program-prefix= \
			--with-hwloc=external \
			--with-libltdl \
			--without-ofi \
			--enable-mpi-fortran=usempi \
			--enable-mpi-cxx \
			--enable-cxx-exceptions \
			--with-libevent=external \
			--enable-mca-no-build=verbs,btl_openib,oob_ud \
			--without-verbs \
			--with-wrapper-ldflags=-Wl,-rpath=-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
			ompi_cv_fortran_ignore_tkr_data=0

TEST_TARGET=	check

PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	openmpi-5*

MANDIRS=	${PREFIX}/${MPIDIR}/share/man

PLIST_SUB+=	MPIDIR=${MPIDIR}

OPTIONS_DEFINE=			AVX DEBUG IPV6 SLURM
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

IPV6_CONFIGURE_ENABLE=	ipv6

SLURM_LIB_DEPENDS=	libslurm.so:sysutils/slurm-wlm
SLURM_CONFIGURE_WITH=	slurm
SLURM_PLIST_FILES=	${MPIDIR}/lib/openmpi/mca_ess_slurm.la \
			${MPIDIR}/lib/openmpi/mca_ess_slurm.so \
			${MPIDIR}/lib/openmpi/mca_plm_slurm.la \
			${MPIDIR}/lib/openmpi/mca_plm_slurm.so \
			${MPIDIR}/lib/openmpi/mca_ras_slurm.la \
			${MPIDIR}/lib/openmpi/mca_ras_slurm.so \
			${MPIDIR}/lib/openmpi/mca_schizo_slurm.la \
			${MPIDIR}/lib/openmpi/mca_schizo_slurm.so \
			${MPIDIR}/share/openmpi/help-plm-slurm.txt \
			${MPIDIR}/share/openmpi/help-ras-slurm.txt

.include <bsd.port.options.mk>

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch
.endif

.if ${ARCH} != aarch64 && ${ARCH} != amd64 && ${ARCH} != i386 && !${ARCH:Mpowerpc*}
PLIST_SUB+=	NO_MCA_PATCHER_OVERWRITE="@comment "
.else
PLIST_SUB+=	NO_MCA_PATCHER_OVERWRITE=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${LOCALBASE}/libdata/pkgconfig|g' \
		${WRKSRC}/ompi/tools/wrappers/Makefile.am \
		${WRKSRC}/ompi/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/tools/wrappers/Makefile.am \
		${WRKSRC}/opal/tools/wrappers/Makefile.in \
		${WRKSRC}/orte/tools/wrappers/Makefile.am \
		${WRKSRC}/orte/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/mca/pmix/pmix3x/pmix/Makefile.am \
		${WRKSRC}/opal/mca/pmix/pmix3x/pmix/Makefile.in
	${REINPLACE_CMD} 's|define MCA_hwloc_external_.*header "|&${LOCALBASE}/include/|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
