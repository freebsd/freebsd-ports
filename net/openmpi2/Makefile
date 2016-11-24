# $FreeBSD$

PORTNAME=	openmpi
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v${PORTVERSION:R}/downloads/
PKGNAMESUFFIX=	2

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High Performance Message Passing Library

LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libltdl.so:devel/libltdl \
		libevent.so:devel/libevent2 \
		libmunge.so:security/munge

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
# :keepla because port uses lt_dlopen
USES=		execinfo fortran gmake libtool:keepla perl5 pkgconfig tar:bzip2
USE_PERL5=	build

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${PKGBASE}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
			--program-prefix= \
			--with-hwloc=${LOCALBASE} \
			--with-libltdl=${LOCALBASE} \
			--enable-mpi-fortran=usempi \
			--enable-mpi-cxx \
			--enable-cxx-exceptions \
			--enable-heterogeneous \
			--enable-mpi-thread-multiple \
			--with-libevent=${LOCALBASE}/include \
			--with-libevent-libdir=${LOCALBASE}/lib \
			ompi_cv_fortran_ignore_tkr_data=0

LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib \
		${PREFIX}/${MPIDIR}/lib/openmpi

MANPREFIX=	${PREFIX}/${MPIDIR}

OPTIONS_DEFINE=	DEBUG IPV6 SLURM TORQUE
TORQUE_DESC=	Enable Torque support
SLURM_DESC=	Enable SLURM support
OPTIONS_DEFAULT=	SLURM
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

IPV6_CONFIGURE_ENABLE=	ipv6

TORQUE_CONFIGURE_ON=	--with-tm=${LOCALBASE}
TORQUE_CONFIGURE_OFF=	--without-tm
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
			${MPIDIR}/share/openmpi/help-plm-slurm.txt \
			${MPIDIR}/share/openmpi/help-ras-slurm.txt

BROKEN_sparc64=		Does not compile on sparc64

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/${MPIDIR}/libdata/pkgconfig|g' \
		${WRKSRC}/ompi/tools/wrappers/Makefile.am \
		${WRKSRC}/ompi/tools/wrappers/Makefile.in \
		${WRKSRC}/opal/tools/wrappers/Makefile.am \
		${WRKSRC}/opal/tools/wrappers/Makefile.in \
		${WRKSRC}/orte/tools/wrappers/Makefile.am \
		${WRKSRC}/orte/tools/wrappers/Makefile.in

.include <bsd.port.mk>
