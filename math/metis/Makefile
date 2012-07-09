# New ports collection makefile for:	METIS
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	metis
PORTVERSION=	5.0.2
CATEGORIES=	math
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A package for unstructured graph partitioning

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

CONFLICTS=	metis-4* metis-edf-[0-9]*

USE_CMAKE=	yes

OPTIONS_DEFINE =	OPENMP STATIC SHARED

OPENMP_DESC=	multithreading via OpenMP
#PROFILE_DESC=	profiling libraries
SHARED_DESC=	shared library and dynamically-linked executables
STATIC_DESC=	libmetis archive

OPTIONS_DEFAULT=	SHARED STATIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
.if !empty(CC:T:M*clang*)
IGNORE =	: clang does not support OpenMP. Disable the OPENMP option or\
		use another compiler
.endif
CMAKE_ARGS+=	-DOPENMP=1
.endif

#.if ${PORT_OPTIONS:MPROFILE}
#.if !exists(/usr/lib/libc_p.a)
#IGNORE =	: you have enabled the PROFILE option, but have not installed \
#		the base system profiling libraries
#.endif
#ALL_TARGET_PROFILE=		metis
#CMAKE_ARGS_PROFILE=		-DGPROF=1
#PLIST_SUB+=			PROFILE=""
##PROFILE_FLAGS ?=		-pg
#WRKSRC_PROFILE =		${WRKSRC}_PROFILE
#INSTALL_WRKSRC_PROFILE =	${WRKSRC_PROFILE}/libmetis
#.else
#PLIST_SUB+=			PROFILE="@comment "
#.endif

.if ${PORT_OPTIONS:MSHARED}
ALL_TARGET_SHARED=	all
CMAKE_ARGS_SHARED=	-DSHARED=1
PLIST_SUB+=		SHARED=""
.if ${ARCH} == "sparc64"
SHARED_FLAGS?=		-fPIC
.else
SHARED_FLAGS?=		-fpic
.endif
SHLIB_MAJOR?=		2
CMAKE_ARGS+=		-DSHLIB_MAJOR="${SHLIB_MAJOR}"
USE_LDCONFIG=		yes
WRKSRC_SHARED=		${WRKSRC}_SHARED
INSTALL_WRKSRC_SHARED=	${WRKSRC_SHARED}
.else
PLIST_SUB+=		SHARED="@comment "
.endif

.if ${PORT_OPTIONS:MSTATIC}
ALL_TARGET_STATIC=	metis
PLIST_SUB+=		STATIC=""
WRKSRC_STATIC=		${WRKSRC}
INSTALL_WRKSRC_STATIC=	${WRKSRC_STATIC}/libmetis
.else
PLIST_SUB+=		STATIC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^# Add compiler flags/,/^$$/d" \
	-e "/^check_include_file(execinfo.h/d" \
	${WRKSRC}/GKlib/GKlibSystem.cmake
	@${REINPLACE_CMD} -e "\|/home/karypis/|d" \
	${WRKSRC}/programs/CMakeLists.txt
.for o in SHARED #PROFILE
.if ${PORT_OPTIONS:M${o}}
	@${CP} -R ${WRKSRC} ${WRKSRC_${o}}
.endif
.endfor

do-configure:
.for o in SHARED STATIC #PROFILE
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nConfiguring ${o}:\n\n\n"
	@cd ${WRKSRC_${o}}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} \
	${CMAKE_ARGS:C|${CFLAGS}|& ${${o}_FLAGS}|g} ${CMAKE_ARGS_${o}} \
	-DGKLIB_PATH="${WRKSRC_${o}}/GKlib" ${CMAKE_SOURCE_PATH}
.endif
.endfor

do-build:
.for o in SHARED STATIC #PROFILE
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nBuilding ${o}:\n\n\n"
	@cd ${WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} ${ALL_TARGET_${o}}
.endif
.endfor

check regression-test test: build
	cd ${WRKSRC_SHARED}/graphs ; ../programs/gpmetis ./4elt.graph 5

do-install:
.for o in SHARED STATIC #PROFILE
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nInstalling ${o}:\n\n\n"
	@cd ${INSTALL_WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install
.endif
.endfor

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	manual.pdf

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
