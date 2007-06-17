# New ports collection makefile for:	fvm
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	fvm
PORTVERSION=	0.6.3
CATEGORIES=	science parallel
MASTER_SITES=	http://www.edf.fr/html/RetD/livraison_saturne_${REL_DATE}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Finite Volume Mesh

LIB_DEPENDS=	med.2:${PORTSDIR}/french/med		\
		bft.1:${PORTSDIR}/science/bft		\
		hdf5.0:${PORTSDIR}/science/hdf5		\
		cgns.0:${PORTSDIR}/science/cgnslib

REL_DATE=	070305

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-bft-prefix=${LOCALBASE}	\
		--with-hdf5-prefix=${LOCALBASE}	\
		--with-cgns-prefix=${LOCALBASE}	\
		--with-med-prefix=${LOCALBASE}
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

.if defined(WITH_LAM)
BUILD_DEPENDS+=	${LOCALBASE}/lib/liblam.a:${PORTSDIR}/net/lam
RUN_DEPENDS+=	${LOCALBASE}/bin/lamboot:${PORTSDIR}/net/lam
CONFIGURE_ARGS+=	--with-mpi-prefix=${LOCALBASE}
.elif defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS+=	--with-mpi-prefix=${LOCALBASE}/mpi/openmpi
.else
BUILD_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/mpich2/bin/mpirun:${PORTSDIR}/net/mpich2
CONFIGURE_ARGS+=	--with-mpi-prefix=${LOCALBASE}/mpich2
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

pre-configure:
	# No useful doc there
	${REINPLACE_CMD} -e 's|tests doc|tests|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
