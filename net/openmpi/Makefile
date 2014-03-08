# $FreeBSD$

# TODO:
#  - etc/*.sample support

PORTNAME=	openmpi
DISTVERSION=	1.6.5
PORTREVISION=	2
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.6/downloads/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High Performance Message Passing Library

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libltdl.so:${PORTSDIR}/devel/libltdl

CONFLICTS=	openmpi-devel-1.7.*

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USES=		fortran gmake pkgconfig

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${UNIQUENAME}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
			--program-prefix= \
			--with-hwloc=${LOCALBASE} \
			--with-libltdl=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib \
		${PREFIX}/${MPIDIR}/lib/openmpi

MANPREFIX=	${PREFIX}/${MPIDIR}

OPTIONS_DEFINE=	IPV6 SLURM TORQUE VT
TORQUE_DESC=	Enable Torque support
SLURM_DESC=	Enable SLURM support
VT_DESC=		Enable VampirTrace support
OPTIONS_DEFAULT=	IPV6
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6

TORQUE_CONFIGURE_ON=	--with-tm=${LOCALBASE}
TORQUE_CONFIGURE_OFF=	--without-tm
TORQUE_LIB_DEPENDS=	libtorque.so:${PORTSDIR}/sysutils/torque
TORQUE_PLIST_FILES=	${MPIDIR}/lib/openmpi/mca_plm_tm.so \
			${MPIDIR}/lib/openmpi/mca_plm_tm.la \
			${MPIDIR}/lib/openmpi/mca_ras_tm.la \
			${MPIDIR}/lib/openmpi/mca_ras_tm.so \
			${MPIDIR}/lib/openmpi/mca_ess_tm.so \
			${MPIDIR}/lib/openmpi/mca_ess_tm.la \
			${MPIDIR}/share/openmpi/help-plm-tm.txt \
			${MPIDIR}/share/openmpi/help-ras-tm.txt

SLURM_CONFIGURE_WITH=	slurm
SLURM_LIB_DEPENDS=	libslurm.so:${PORTSDIR}/sysutils/slurm-hpc
SLURM_PLIST_FILES=	${MPIDIR}/lib/openmpi/mca_ess_slurm.la \
			${MPIDIR}/lib/openmpi/mca_ess_slurm.so \
			${MPIDIR}/lib/openmpi/mca_ess_slurmd.la \
			${MPIDIR}/lib/openmpi/mca_ess_slurmd.so \
			${MPIDIR}/lib/openmpi/mca_plm_slurm.la \
			${MPIDIR}/lib/openmpi/mca_plm_slurm.so \
			${MPIDIR}/lib/openmpi/mca_ras_slurm.la \
			${MPIDIR}/lib/openmpi/mca_ras_slurm.so \
			${MPIDIR}/share/openmpi/help-plm-slurm.txt \
			${MPIDIR}/share/openmpi/help-ras-slurm.txt

VT_CONFIGURE_OFF=	--enable-contrib-no-build=vt --disable-vt
VT_USE=			JAVA=yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
