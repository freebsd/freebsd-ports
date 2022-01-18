PORTNAME=	openmpi
PORTVERSION=	4.1.2
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v${PORTVERSION:R}/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Performance Message Passing Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2 \
		libltdl.so:devel/libltdl \
		libevent.so:devel/libevent \
		libmunge.so:security/munge

# :keepla because port uses lt_dlopen
USES=		fortran gmake libtool:keepla localbase perl5 \
		pkgconfig shebangfix tar:bzip2

HAS_CONFIGURE=	yes
USE_PERL5=	build

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PKGBASE}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

# Workaround for https://github.com/open-mpi/ompi/issues/7516
CONFIGURE_ENV+=		DISABLE_gds_ds12=1 DISABLE_gds_ds21=1

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
			--program-prefix= \
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

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib

MANPREFIX=	${PREFIX}/${MPIDIR}

SHEBANG_FILES=	ompi/mca/common/monitoring/profile2mat.pl \
		ompi/mca/common/monitoring/aggregate_profile.pl

OPTIONS_DEFINE=			AVX DEBUG IPV6 SLURM TORQUE
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
TORQUE_DESC=	Enable Torque support

AVX_CONFIGURE_OFF=	--enable-mca-no-build=op-avx

DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

IPV6_CONFIGURE_ENABLE=	ipv6

TORQUE_CONFIGURE_WITH=	tm
TORQUE_LIB_DEPENDS=	libtorque.so:sysutils/torque
TORQUE_PLIST_FILES=	${MPIDIR}/lib/openmpi/mca_plm_tm.so \
			${MPIDIR}/lib/openmpi/mca_plm_tm.la \
			${MPIDIR}/lib/openmpi/mca_ras_tm.la \
			${MPIDIR}/lib/openmpi/mca_ras_tm.so \
			${MPIDIR}/lib/openmpi/mca_ess_tm.so \
			${MPIDIR}/lib/openmpi/mca_ess_tm.la \
			${MPIDIR}/share/openmpi/help-plm-tm.txt \
			${MPIDIR}/share/openmpi/help-ras-tm.txt

SLURM_CONFIGURE_WITH=	slurm
SLURM_LIB_DEPENDS=	libslurm.so:sysutils/slurm-wlm
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

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${LOCALBASE}/libdata/pkgconfig|g' \
		${WRKSRC}/ompi/tools/wrappers/Makefile.am \
		${WRKSRC}/ompi/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/tools/wrappers/Makefile.am \
		${WRKSRC}/opal/tools/wrappers/Makefile.in \
		${WRKSRC}/orte/tools/wrappers/Makefile.am \
		${WRKSRC}/orte/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/mca/pmix/pmix3x/pmix/Makefile.am \
		${WRKSRC}/opal/mca/pmix/pmix3x/pmix/Makefile.in
	@${REINPLACE_CMD} 's|define MCA_hwloc_external_.*header "|&${LOCALBASE}/include/|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
