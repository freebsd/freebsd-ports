# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	metis
PORTVERSION=	5.1.0
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Package for unstructured graph partitioning

LICENSE=	APACHE20

USES=		cmake:noninja compiler:c11

CONFLICTS=	metis-edf-[0-9]* metis4-4*

PORTDOCS=	manual.pdf

BINS=		cmpfillin gpmetis graphchk m2gmetis mpmetis ndmetis
SHLIB_MAJOR?=	2

OPTIONS_DEFINE=		DOCS OPENMP SHARED STATIC
OPTIONS_DEFAULT=	SHARED STATIC
OPTIONS_SUB=		yes

OPENMP_DESC=	multithreading via OpenMP
SHARED_DESC=	shared library and dynamically-linked executables
STATIC_DESC=	libmetis archive

OPENMP_CMAKE_BOOL=	OPENMP
OPENMP_USES=		compiler:openmp

SHARED_USE=	LDCONFIG=yes

CMAKE_ARGS_SHARED=	-DSHARED=1 -DSHLIB_MAJOR="${SHLIB_MAJOR}"
ALL_TARGET_SHARED=	all
WRKSRC_SHARED=		${WRKSRC}_SHARED
INSTALL_WRKSRC_SHARED=	${WRKSRC_SHARED}

ALL_TARGET_STATIC=	metis
WRKSRC_STATIC=		${WRKSRC}
INSTALL_WRKSRC_STATIC=	${WRKSRC_STATIC}/libmetis

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
.endif

pre-configure:
	@${REINPLACE_CMD} -e "/^# Add compiler flags/,/^$$/d" \
	-e "/^check_include_file(execinfo.h/d" \
	${WRKSRC}/GKlib/GKlibSystem.cmake
	@${REINPLACE_CMD} -e "\|/home/karypis/|d" \
	${WRKSRC}/programs/CMakeLists.txt
.if ${ARCH:M*64*}
	@${REINPLACE_CMD}-e \
		's|IDXTYPEWIDTH 32|IDXTYPEWIDTH 64|' \
		${WRKSRC}/include/metis.h
.endif

pre-configure-SHARED-on:
	@${CP} -R ${WRKSRC} ${WRKSRC_SHARED}

do-configure:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nConfiguring ${o}:\n\n\n"
	@cd ${WRKSRC_${o}}; ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
	${CMAKE_ARGS:C|${CFLAGS}|& ${${o}_FLAGS}|g} ${CMAKE_ARGS_${o}} \
	-DGKLIB_PATH="${WRKSRC_${o}}/GKlib" ${CMAKE_SOURCE_PATH}
.endif
.endfor

do-build:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nBuilding ${o}:\n\n\n"
	@cd ${WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} ${ALL_TARGET_${o}}
.endif
.endfor
.if ${PORT_OPTIONS:MSHARED}
	@cd ${WRKSRC_SHARED}/programs; ${STRIP_CMD} ${BINS}
	@cd ${WRKSRC_SHARED}/libmetis; ${STRIP_CMD} libmetis.so.*
.endif
.if ${PORT_OPTIONS:MSTATIC}
	@cd ${WRKSRC_STATIC}/libmetis; ${STRIP_CMD} libmetis.a
.endif

check regression-test test: build
	cd ${WRKSRC_SHARED}/graphs ; ../programs/gpmetis ./4elt.graph 5

do-install:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nInstalling ${o}:\n\n\n"
	@cd ${INSTALL_WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install
.endif
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
