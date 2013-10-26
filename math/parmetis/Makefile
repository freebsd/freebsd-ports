# Created by: Eoin Lawless (eoin@maths.tcd.ie)
# $FreeBSD$

PORTNAME=	ParMetis
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	math parallel
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A package for parallel (mpi) unstructured graph partitioning

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

OPTIONS_DEFINE=	OPENMPI DOCS
OPENMPI_DESC=	Use openmpi instead of mpich2

USES=		cmake
USE_GMAKE=	yes

PORTDOCS=	manual.pdf
PLIST_FILES=	include/parmetis/parmetis.h \
		lib/parmetis/libmetis.a lib/parmetis/libparmetis.a
PLIST_DIRS=	include/parmetis lib/parmetis

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|BUILDDIR =.*|BUILDDIR = build| ; \
		 s|make -C|$$(MAKE) -C|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/metis/GKlib/GKlibSystem.cmake

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} config prefix="${PREFIX}" cc="${MPICC}"

do-install:
	@${MKDIR} ${PREFIX}/include/parmetis
	${INSTALL_DATA} ${WRKSRC}/include/parmetis.h ${PREFIX}/include/parmetis
	@${MKDIR} ${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libmetis/libmetis.a ${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libparmetis/libparmetis.a ${PREFIX}/lib/parmetis
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
