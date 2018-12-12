# $FreeBSD$

PORTNAME=	openmpi
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v${PORTVERSION:R}/downloads/
PKGNAMESUFFIX=	3

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High Performance Message Passing Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to package: pkg-static: mca_patcher_overwrite.la: No such file or directory
BROKEN_armv6=		fails to package: pkg-static: mca_patcher_overwrite.la: No such file or directory
BROKEN_armv7=		fails to package: pkg-static: mca_patcher_overwrite.la: No such file or directory
BROKEN_sparc64=		fails to compile on sparc64

LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libltdl.so:devel/libltdl \
		libevent.so:devel/libevent \
		libmunge.so:security/munge

# :keepla because port uses lt_dlopen
USES=		fortran gmake libtool:keepla localbase perl5 \
		pkgconfig shebangfix tar:bzip2

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_PERL5=	build

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PKGBASE}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
			--program-prefix= \
			--with-hwloc=external \
			--with-libltdl \
			--enable-mpi-fortran=usempi \
			--enable-mpi-cxx \
			--enable-cxx-exceptions \
			--enable-mpi-thread-multiple \
			--with-libevent=external \
			--enable-mca-no-build=verbs,btl_openib,oob_ud \
			--without-verbs \
			--with-wrapper-ldflags=-Wl,-rpath=-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
			ompi_cv_fortran_ignore_tkr_data=0

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib \
		${PREFIX}/${MPIDIR}/lib/openmpi

MANPREFIX=	${PREFIX}/${MPIDIR}

SHEBANG_FILES=	ompi/mca/common/monitoring/profile2mat.pl \
		ompi/mca/common/monitoring/aggregate_profile.pl

OPTIONS_DEFINE=	DEBUG IPV6 SLURM TORQUE
TORQUE_DESC=	Enable Torque support
SLURM_DESC=	Enable SLURM support
OPTIONS_DEFAULT=	SLURM
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

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

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/${MPIDIR}/libdata/pkgconfig|g' \
		${WRKSRC}/ompi/tools/wrappers/Makefile.am \
		${WRKSRC}/ompi/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/tools/wrappers/Makefile.am \
		${WRKSRC}/opal/tools/wrappers/Makefile.in \
		${WRKSRC}/orte/tools/wrappers/Makefile.am \
		${WRKSRC}/orte/tools/wrappers/Makefile.in
	@${REINPLACE_CMD} 's|define MCA_hwloc_external_.*header "|&${LOCALBASE}/include/|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
