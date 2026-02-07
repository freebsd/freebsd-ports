PORTNAME=	metis
DISTVERSION=	5.1.0-p13
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/petsc/pkg-metis/get/
DISTNAME=	${LGCOMMIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package for unstructured graph partitioning
WWW=		https://bitbucket.org/petsc/pkg-metis

LICENSE=	APACHE20

# Keep cmake:insource to be used by math/parmetis
USES=		cmake:insource,noninja compiler:c11 tar:bzip2

SHCOMMIT=	08c3082720ff
LGCOMMIT=	${SHCOMMIT}9114b8e3cbaa4484a26739cd7d2d
WRKSRC=		${WRKDIR}/petsc-pkg-metis-${SHCOMMIT}

BINS=		cmpfillin gpmetis graphchk m2gmetis mpmetis ndmetis
SHLIB_MAJOR?=	2

OPTIONS_DEFINE=		OPENMP SHARED STATIC
OPTIONS_DEFAULT=	SHARED STATIC
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_DEFAULT_i386=	OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_SUB=		yes

OPENMP_DESC=	multithreading via OpenMP
SHARED_DESC=	shared library and dynamically-linked executables
STATIC_DESC=	libmetis archive

OPENMP_CMAKE_BOOL=	OPENMP

SHARED_USE=	LDCONFIG=yes

CMAKE_ARGS_SHARED=	-DSHARED=1 -DSHLIB_MAJOR:STRING="${SHLIB_MAJOR}"	\
			-DMETIS_INSTALL:BOOL=1
ALL_TARGET_SHARED=	all
WRKSRC_SHARED=		${WRKSRC}_SHARED
INSTALL_WRKSRC_SHARED=	${WRKSRC_SHARED}
CMAKE_SOURCE_PATH_SHARED=${WRKSRC_SHARED}

ALL_TARGET_STATIC=	metis
WRKSRC_STATIC=		${WRKSRC}
INSTALL_WRKSRC_STATIC=	${WRKSRC_STATIC}/libmetis
CMAKE_SOURCE_PATH_STATIC=${WRKSRC_STATIC}

CFLAGS+=	-fpic

.include <bsd.port.options.mk>

.if ${ARCH:M*64*}
CMAKE_ARGS+=	-DMETIS_USE_LONGINDEX:BOOL="On"
.endif

pre-configure:
	${REINPLACE_CMD} -e "/^# Add compiler flags/,/^$$/d" \
		-e "/^check_include_file(execinfo.h/d" \
		${WRKSRC}/GKlib/GKlibSystem.cmake

pre-configure-SHARED-on:
	${CP} -R ${WRKSRC} ${WRKSRC_SHARED}
	${REINPLACE_CMD} -e '/programs/s|#add_subdir|add_subdir|'	\
		${WRKSRC_SHARED}/CMakeLists.txt

do-configure:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nConfiguring ${o}:\n\n\n"
	cd ${WRKSRC_${o}}; ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
	${CMAKE_ARGS:C|${CFLAGS}|& ${${o}_FLAGS}|g} ${CMAKE_ARGS_${o}} \
	-DGKLIB_PATH="${WRKSRC_${o}}/GKlib" ${CMAKE_SOURCE_PATH_${o}}
.endif
.endfor

do-build:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nBuilding ${o}:\n\n\n"
	cd ${WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} ${ALL_TARGET_${o}}
.endif
.endfor
.if ${PORT_OPTIONS:MSHARED}
	cd ${WRKSRC_SHARED}/programs; ${STRIP_CMD} ${BINS}
	cd ${WRKSRC_SHARED}/libmetis; ${STRIP_CMD} libmetis.so.*
.endif
.if ${PORT_OPTIONS:MSTATIC}
	cd ${WRKSRC_STATIC}/libmetis; ${STRIP_CMD} libmetis.a
.endif

.if defined(MAINTAINER_MODE)
# No more graph directory, to be taken from an original tarball
# e.g. https://people.freebsd.org/~thierry/metis-5.1.0.tar.gz
test: build
	cd ${WRKSRC_SHARED}/graphs ; ../programs/gpmetis ./4elt.graph 5
.endif

do-install:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\nInstalling ${o}:\n\n\n"
	cd ${INSTALL_WRKSRC_${o}}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install
.endif
.endfor

.include <bsd.port.mk>
