# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	fvm
PORTVERSION=	0.15.5
PORTREVISION=	2
CATEGORIES=	science parallel
MASTER_SITES=	http://code-saturne.org/releases/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Finite Volume Mesh

LICENSE=	LGPL21

LIB_DEPENDS=	libmed.so:french/med	\
		libbft.so:science/bft	\
		libhdf5.so:science/hdf5	\
		libcgns.so:science/cgnslib

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}	\
		--with-hdf5=${LOCALBASE}	\
		--with-cgns=${LOCALBASE}	\
		--with-med=${LOCALBASE}
INSTALL_TARGET=	install-strip

.if defined(WITH_LAM)
BUILD_DEPENDS+=	${LOCALBASE}/lib/liblam.a:net/lam
RUN_DEPENDS+=	${LOCALBASE}/bin/lamboot:net/lam
CONFIGURE_ARGS+=	--with-mpi=${LOCALBASE}
.elif defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
CONFIGURE_ARGS+=	--with-mpi=${LOCALBASE}/mpi/openmpi
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:net/mpich2
CONFIGURE_ARGS+=	--with-mpi=${LOCALBASE}
# Do not directly depend on Fortran, but FFLAGS needed to link with mpich2
USES+=		fortran
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

TESTSBIN=	fvm_file_test fvm_interface_test fvm_selector_postfix_test fvm_selector_test

pre-configure:
	${REINPLACE_CMD} -e 's|-lmpich|-lmpich -lmpl|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	# No useful doc there
	${REINPLACE_CMD} -e 's|tests doc|tests|' ${WRKSRC}/Makefile.in

regression-test:
.for pg in ${TESTSBIN}
	(cd ${WRKSRC}/tests; ./${pg})
.endfor

.include <bsd.port.mk>
