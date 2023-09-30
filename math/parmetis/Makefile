PORTNAME=	ParMetis
PORTVERSION=	4.0.3
PORTREVISION=	8
CATEGORIES=	math parallel
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package for parallel (MPI) unstructured graph partitioning
WWW=		http://glaros.dtc.umn.edu/gkhome/metis/parmetis/overview

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

USES=		cmake:insource,noninja gmake
USE_LDCONFIG=	${PREFIX}/lib/parmetis

OPTIONS_DEFINE=	OPENMPI DOCS STATIC
OPENMPI_DESC=	Use openmpi instead of mpich
OPTIONS_SUB=	yes

OPENMPI_USES=			mpi:openmpi
OPENMPI_USES_OFF=		mpi

STATIC_DESC=			Do not build and install shared library
STATIC_VARS_OFF=		SH_FLAG="shared=1"

CFLAGS+=	-fPIC

.include <bsd.port.options.mk>

pre-configure:
	@${REINPLACE_CMD} -e \
		's|BUILDDIR =.*|BUILDDIR = build| ; \
		 s|make -C|$$(MAKE) -C| ; \
		 s|$$(MAKEFLAGS)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|"-O3"|""|' ${WRKSRC}/metis/GKlib/GKlibSystem.cmake
.if ((${ARCH}=="amd64") || (${ARCH}=="aarch64") || (${ARCH}=="ppc64"))
	@${REINPLACE_CMD} -e \
		's|IDXTYPEWIDTH 32|IDXTYPEWIDTH 64|' \
		${WRKSRC}/metis/include/metis.h
.endif
	@${REINPLACE_CMD} -e \
		'/target_link_libraries(.* parmetis)/s/\(parmetis\)/& -lexecinfo/' \
		${WRKSRC}/programs/CMakeLists.txt

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} config prefix="${PREFIX}" cc="${MPICC}" cxx="${MPICXX}" ${SH_FLAG}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/parmetis \
		${STAGEDIR}${PREFIX}/lib/parmetis \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/include/parmetis.h \
		${WRKSRC}/metis/include/metis.h \
		${STAGEDIR}${PREFIX}/include/parmetis
.if ${PORT_OPTIONS:MSTATIC}
	${INSTALL_DATA} ${WRKSRC}/build/libmetis/libmetis.a \
		${STAGEDIR}${PREFIX}/lib/parmetis
	${INSTALL_DATA} ${WRKSRC}/build/libparmetis/libparmetis.a \
		${STAGEDIR}${PREFIX}/lib/parmetis
.else
	${INSTALL_DATA} ${WRKSRC}/build/libmetis/libmetis.so \
		${STAGEDIR}${PREFIX}/lib/parmetis/libmetis.so.2
	${INSTALL_LIB} ${WRKSRC}/build/libparmetis/libparmetis.so \
		${STAGEDIR}${PREFIX}/lib/parmetis/libparmetis.so.2
	cd ${STAGEDIR}${PREFIX}/lib/parmetis &&	\
		${LN} -sf libmetis.so.2 ${STAGEDIR}${PREFIX}/lib/parmetis/libmetis.so && \
		${LN} -sf libparmetis.so.2 ${STAGEDIR}${PREFIX}/lib/parmetis/libparmetis.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/parmetis/libmetis.so.2
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
