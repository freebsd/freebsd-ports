# Created by: Eoin Lawless (eoin@maths.tcd.ie)
# $FreeBSD$

PORTNAME=	ParMetis
PORTVERSION=	4.0
PORTREVISION=	4
CATEGORIES=	math parallel
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Package for parallel (mpi) unstructured graph partitioning

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

OPTIONS_DEFINE=	OPENMPI DOCS
OPENMPI_DESC=	Use openmpi instead of mpich2

USES=		cmake gmake

PLIST_FILES=	include/parmetis/metis.h \
		include/parmetis/parmetis.h \
		lib/parmetis/libmetis.a \
		lib/parmetis/libparmetis.a \
		${DOCSDIR}/manual.pdf
PLIST_DIRS=	include/parmetis \
		lib/parmetis \
		${DOCSDIR}

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
		 s|make -C|$$(MAKE) -C| ; \
		 s|$$(MAKEFLAGS)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/metis/GKlib/GKlibSystem.cmake

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} config prefix="${PREFIX}" cc="${MPICC}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/parmetis \
		${STAGEDIR}${PREFIX}/lib/parmetis \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/include/parmetis.h \
		${WRKSRC}/metis/include/metis.h \
		${STAGEDIR}${PREFIX}/include/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libmetis/libmetis.a \
		${STAGEDIR}${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libparmetis/libparmetis.a \
		${STAGEDIR}${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
