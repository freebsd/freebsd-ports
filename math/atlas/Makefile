# New ports collection makefile for:	atlas
# Date created:		12 February 2001
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atlas
PORTVERSION=	3.8.3
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	SF/math-${PORTNAME}/Stable/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Automatically Tuned Linear Algebra Software (ATLAS)

MANUAL_PACKAGE_BUILD=	Optimizes for the local machine.

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/ATLAS
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=	alpha

USE_FORTRAN=	yes
CCOMPILER=	${CC}
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

.if ${ARCH} == "i386"
POINTER=	32
.endif
.if ${ARCH} == "amd64"
POINTER=	64
.endif
.if ${ARCH} == "sparc64"
POINTER=	64
.endif

.if (${OSVERSION} < 700000) && defined(WITH_GCC42KERNEL)
BUILD_DEPENDS+=	gcc42:${PORTSDIR}/lang/gcc42
KERNELFLAG=	-Ss kern gcc42
.else
KERNELFLAG=	""
.endif

.if defined(WITH_WALL_TIMER)
.  if defined(MHZ) && ( ${ARCH} == "i386" || ${ARCH} == "amd64" )
TIMEFLAG=	-D c -DPentiumCPS=${MHZ}
.  else
TIMEFLAG=	-D c -DWALL
.  endif
.else
TIMEFLAG=	""
.endif

# only used for lapack sub-project
.if defined(WITH_OPTIMIZED_FLAGS)
.if defined(CPUTYPE)
FFLAGS+=	-march=${CPUTYPE} -pipe -O2 -ffast-math
.else
FFLAGS+=	-pipe -O2 -ffast-math
.endif
.endif
.if defined(WITH_STATICLIB)
PLIST_SUB+=	WITH_STATICLIB=""
.else
PLIST_SUB+=	WITH_STATICLIB="@comment "
.endif

post-extract:
	@${ECHO_MSG} 'This port engages in a long, computationally-demanding tuning process.'
	@${ECHO_MSG} 'Builds can take a day or more on older hardware, and temporarily occupy'
	@${ECHO_MSG} 'several hundred megabytes of disk space.  You are advised to disable'
	@${ECHO_MSG} 'all forms of power management or CPU throttling (APM, ACPI, Intel'
	@${ECHO_MSG} 'SpeedStep, AMD PowerNow, AMD Cool and Quiet, p4tcc, powerd, etc.)'
	@${ECHO_MSG} 'that may change the disk I/O or CPU behavior during the build, and'
	@${ECHO_MSG} 'to set operating parameters to static values at which you ultimately'
	@${ECHO_MSG} 'intend to use the software.  You should also avoid placing heavy loads'
	@${ECHO_MSG} 'on the system during the build, and temporarily disable any automatons'
	@${ECHO_MSG} 'that may do so.  If you fail to follow these guidelines, you may prolong'
	@${ECHO_MSG} 'the build, perhaps indefinitely, and you may obtain libraries with'
	@${ECHO_MSG} 'sub-optimal performance.'
	@${ECHO_MSG}
	@${ECHO_MSG} 'Occasionally the autoconfiguration may fail for certain platforms, and'
	@${ECHO_MSG} 'you may have to override the architecture, compiler flags, assembly'
	@${ECHO_MSG} 'language dialect, or pointer bit-width by issuing additional configure'
	@${ECHO_MSG} 'arguments.  Consult the FAQ, installation guide, and errata page at'
	@${ECHO_MSG} 'the project website for help if this is necessary, and notify the'
	@${ECHO_MSG} 'port maintainer.'
	@${ECHO_MSG}
	@${ECHO_MSG} "This port purposely ignores the CC and CFLAGS settings"
	@${ECHO_MSG} "Program and compiler flags are fine-tuned to the gcc 4.2.x"
	@${ECHO_MSG} "compiler, although other gcc versions may be used; gcc 4.1.x"
	@${ECHO_MSG} "is NOT recommended"
	@${ECHO_MSG}
.if !defined(WITH_STATICLIB)
	@${ECHO_MSG} "You can build static libraries with"
	@${ECHO_MSG} "make -DWITH_STATICLIB"
	@${ECHO_MSG}
.endif
.if !defined(WITH_WALL_TIMER)
	@${ECHO_MSG} "If your machine will be solely dedicated to"
	@${ECHO_MSG} "building atlas with gcc during the lengthy optimization"
	@${ECHO_MSG} "process, and not subjected to other loads, you"
	@${ECHO_MSG} "may enable the more accurate wall timer (instead of"
	@${ECHO_MSG} "the default CPU-time timer) with make -DWITH_WALL_TIMER"
	@${ECHO_MSG} "If, in addition, you are on i386 or amd64, you may set MHZ"
	@${ECHO_MSG} "to your CPU clock frequency in MHz (rounded to the nearest"
	@${ECHO_MSG} "integer value) in the build environment for cycle-to-time"
	@${ECHO_MSG} "conversion"
	@${ECHO_MSG}
.endif
.if (${OSVERSION} < 700000)
.if !defined(WITH_GCC42KERNEL)
	@${ECHO_MSG} "If you don't want to make gcc 4.2.x your default compiler (CC),"
	@${ECHO_MSG} "but you want to have ATLAS use it to compile all the kernel"
	@${ECHO_MSG} "routines (this usually results in superior performance, and a"
	@${ECHO_MSG} "slightly faster build), while compiling interface routines and"
	@${ECHO_MSG} "doing any linking with gcc 3.x, make a hybrid build with"
	@${ECHO_MSG} "make -DWITH_GCC42KERNEL"
	@${ECHO_MSG}
.endif
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|%%CC%%|${CCOMPILER}|g" \
		-e "s|%%FC%%|${FC}|g"  ${WRKSRC}/CONFIG/src/atlcomp.txt
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
			  -e "s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g" \
			  -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/CONFIG/src/SpewMakeInc.c

do-configure:
#non-threaded
#dummy f77lib, it is not used.
	${MKDIR} ${WRKSRC}/NON_THREADED ; cd ${WRKSRC}/NON_THREADED ; \
		../configure -v 2 -t 0 ${TIMEFLAG} -b ${POINTER} -Si cputhrchk 0 ${KERNELFLAG} -Ss f77lib " "
	${MKDIR} ${WRKSRC}/NON_THREADED_PIC ; cd ${WRKSRC}/NON_THREADED_PIC ; \
		../configure -v 2 -t 0 -b ${POINTER} -Fa alg '${PICFLAG} -DPIC' ${TIMEFLAG} -Si cputhrchk 0 ${KERNELFLAG} -Ss f77lib " "
#threaded
#dummy f77lib, it is not used.
	cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/thread-patch
	${MKDIR} ${WRKSRC}/THREADED ; cd ${WRKSRC}/THREADED ; \
		../configure -v 2 -b ${POINTER} -Fa alg '${PTHREAD_CFLAGS} ' ${TIMEFLAG} -Si cputhrchk 0 ${KERNELFLAG} -Ss f77lib " "
	${MKDIR} ${WRKSRC}/THREADED_PIC ; cd ${WRKSRC}/THREADED_PIC ; \
		../configure -v 2 -b ${POINTER} -Fa alg '${PTHREAD_CFLAGS} ${PICFLAG} -DPIC' ${TIMEFLAG} -Si cputhrchk 0 ${KERNELFLAG} -Ss f77lib " "

do-build:
# make lapack
.if ! exists(${WRKDIR}/lapack/Makefile)
	@${ECHO_MSG} "===>  Extracting lapack sub project"
	@${MKDIR} ${WRKDIR}/lapack
	@${CP} -r ${PORTSDIR}/math/lapack/files ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/Makefile ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/distinfo ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/pkg-descr ${WRKDIR}/lapack
	@cd ${WRKDIR}/lapack ; ${MAKE} "FFLAGS=${FFLAGS}" FC="${FC}" build WRKDIRPREFIX=""
.endif
.if defined(WITH_STATICLIB)
	(cd ${WRKSRC}/NON_THREADED ; ${MAKE})
	(cd ${WRKSRC}/THREADED ; ${MAKE})
.endif
	(cd ${WRKSRC}/NON_THREADED_PIC ; ${MAKE})
	(cd ${WRKSRC}/THREADED_PIC ; ${MAKE})
test:
	@${MAKE} do-test

ATLAS_LIBS1=libalapack libatlas libcblas libf77blas #libtstatlas
ATLAS_LIBS2=libptcblas libptf77blas
LAPACKWRKSRC=`cd ${WRKDIR}/lapack; ${MAKE} -V WRKSRC WRKDIRPREFIX=""`

post-build:
.if defined(WITH_STATICLIB)
# make atlas-enhanced lapack (static ver)
	(cd ${WRKSRC}; ${MKDIR} tmp1 ; \
		${CP} ${LAPACKWRKSRC}/liblapack.a tmp1 ;\
		cd tmp1 ;\
		ar x liblapack.a ;\
		ar x ../NON_THREADED/lib/liblapack.a ;\
		ar r ../NON_THREADED/lib/libalapack.a *.o ;\
		ranlib ../NON_THREADED/lib/libalapack.a )
#  make atlas-enhanced lapack (static and thread-safe ver)
	(cd ${WRKSRC}; ${MKDIR} tmp2 ; \
		${CP} ${LAPACKWRKSRC}/liblapack.a tmp2 ;\
		cd tmp2 ;\
		ar x liblapack.a ;\
		ar x ../THREADED/lib/liblapack.a ;\
		ar r ../THREADED/lib/libalapack.a *.o ;\
		ranlib ../THREADED/lib/libalapack.a )
.endif
# make atlas-enhanced lapack (shared ver)
	( cd ${WRKSRC}; ${MKDIR} tmp3 ;\
		${CP} ${LAPACKWRKSRC}_shared/liblapack.a tmp3 ;\
		cd tmp3 ;\
		ar x liblapack.a ;\
		ar x ../NON_THREADED_PIC/lib/liblapack.a ;\
		ar r ../NON_THREADED_PIC/lib/libalapack.a *.o ;\
		ranlib ../NON_THREADED_PIC/lib/libalapack.a )
# make atlas-enhanced lapack (shared and thread-safe ver)
	( cd ${WRKSRC}; ${MKDIR} tmp4 ;\
		${CP} ${LAPACKWRKSRC}_shared/liblapack.a tmp4 ;\
		cd tmp4 ;\
		ar x liblapack.a ;\
		ar x ../THREADED_PIC/lib/liblapack.a ;\
		ar r ../THREADED_PIC/lib/libalapack.a *.o ;\
		ranlib ../THREADED_PIC/lib/libalapack.a )

# make atlas shared library
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/NON_THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}.so.2 -x -soname ${i}.so.2 --whole-archive ${i}.a )
.endfor

# make atlas shared (thread-safe) library
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}_r.so.2 -x -soname ${i}_r.so.2 --whole-archive ${i}.a )
.endfor
.for i in ${ATLAS_LIBS2}
	( cd ${WRKSRC}/THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}.so.2 -x -soname ${i}.so.2 --whole-archive ${i}.a )
.endfor
do-install:
.for i in ${ATLAS_LIBS1}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/NON_THREADED/lib/${i}.a       ${PREFIX}/lib
.endif
	@${INSTALL_DATA} ${WRKSRC}/NON_THREADED_PIC/lib/${i}.so.2    ${PREFIX}/lib
	@${LN} -sf ${i}.so.2 ${PREFIX}/lib/${i}.so
.endfor
.for i in ${ATLAS_LIBS1}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/THREADED/lib/${i}.a       ${PREFIX}/lib/${i}_r.a
.endif
	@${INSTALL_DATA} ${WRKSRC}/THREADED_PIC/lib/${i}_r.so.2    ${PREFIX}/lib/${i}_r.so.2
	@${LN} -sf ${i}_r.so.2 ${PREFIX}/lib/${i}_r.so
.endfor
.for i in ${ATLAS_LIBS2}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/THREADED/lib/${i}.a       ${PREFIX}/lib
.endif
	@${INSTALL_DATA} ${WRKSRC}/THREADED_PIC/lib/${i}.so.2    ${PREFIX}/lib
	@${LN} -sf ${i}.so.2 ${PREFIX}/lib/${i}.so
.endfor

	@${INSTALL_DATA} ${WRKSRC}/include/cblas.h   ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/clapack.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <${FILESDIR}/Makefile.test>
.include <bsd.port.post.mk>
