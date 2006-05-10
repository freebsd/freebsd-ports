# New ports collection makefile for:	atlas-devel
# Date created:		14 September 2003
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc.

PORTNAME=	atlas
PORTVERSION=	3.7.11
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Development version of math/atlas

NO_PACKAGE=	"Optimizes for the local machine, so a package is not generally useful.  Set FORCE_PACKAGE to override"

CONFLICTS=	elmer-mathlibs-1*

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501000 && ${ARCH} == "alpha"
USE_GCC=3.4
.endif

# only affects for lapack sub project
.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.endif

post-patch:
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO_CMD} "You can optimize lapack sub project by setting WITH_OPTIMIZED_FLAGS=yes."
.endif
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g' \
			  -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g' \
		${WRKSRC}/config.c
.if defined(PORTS_ARCH)
	@${REINPLACE_CMD} -e 's+%%PORTS_ARCH%%+${PORTS_ARCH}+g' \
			-e 's+%%HAVE_ARCH%%+1+g' ${WRKSRC}/config.c
.else
	@${REINPLACE_CMD} -e 's+%%PORTS_ARCH%%+0+g' \
			-e 's+%%HAVE_ARCH%%+0+g' ${WRKSRC}/config.c
.endif
.if (${MACHINE_ARCH} == "alpha")
EXTRA_PATCHES+=	${FILESDIR}/alpha-patch
.endif

.if ${MACHINE_ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

ANSWER_i386?=	${PRINTF} "\n\n\n\n\n\n\n\n\n\n"
ANSWER_ia64?=	${PRINTF} "\n\n\n2\n\n\n\n\nf77\n-O2 -static\n\n"

.if defined(PACKAGE_BUILDING) && (${MACHINE_ARCH} == "i386")
PORTS_ARCH=IntP5
.endif

.if !defined(ANSWER_${ARCH})
ANSWER=	${ANSWER_i386}
.else
ANSWER=	${ANSWER_${ARCH}}
.endif

.if defined(TIMING_TOLERANCE)
EXTRA_PATCHES+=	${FILESDIR}/timing_tolerance-patch
.endif

.if defined(WITH_STATICLIB)
PLIST_SUB=      WITH_STATICLIB=""
.else
PLIST_SUB=      WITH_STATICLIB="@comment "
.endif

pre-configure:
	@${ECHO_MSG} "Warning:"
	@${ECHO_MSG} "Building this port can take long time"
	@${ECHO_MSG} "for slow computers (over 1 day)."
	@${ECHO_MSG} "And sometimes stop building for Athlon."
	@${ECHO_MSG} "In this case please retype make or rebuild whole atlas."
	@${ECHO_MSG}
pre-build:
.if !defined(PORTS_ARCH)
	@${ECHO_MSG} "Warning:"
	@${ECHO_MSG} "If your arch is not correctly detected, you can specify"
	@${ECHO_MSG} "by yourself."
	@${ECHO_MSG} "for example : make PORTS_ARCH=P5Int"
	@${ECHO_MSG} "Available architectures for x86 are:"
	@${ECHO_MSG} "IntP5, IntP5MMX, IntPPRO, IntPII, IntPIII, IntP4, IntP4E"
	@${ECHO_MSG} "IntP4E64, TMEff, AmdAthlon,AmdHammer32, AmdHammer64"
	@${ECHO_MSG}
.endif
.if !defined(TIMING_TOLERANCE)
	@${ECHO_MSG} "If your install dies with unable to get timings in tolerance"
	@${ECHO_MSG} "First please refer http://math-atlas.sourceforge.net/errata.html#tol"
	@${ECHO_MSG} "and you can build with"
	@${ECHO_MSG} "make clean; make -DTIMING_TOLERANCE"
	@${ECHO_MSG} "if your build still dies, you can type make again, (and again...)"
	@${ECHO_MSG}
.endif
.if !defined(WITH_STATICLIB)
	@${ECHO_MSG} "You can build static libraries with"
	@${ECHO_MSG} "make -DWITH_STATICLIB"
	@${ECHO_MSG}
.endif

do-configure:
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} xconfig && \
		${ANSWER} | ./xconfig -N 1 -c ${CC} -f ${FC} -m ${CC} -g ${CC} -x ${CC} -a NON_THREADED && \
		${ANSWER} | ./xconfig -N 1 -c ${CC} -f ${FC} -m ${CC} -g ${CC} -x ${CC} -a NON_THREADED_PIC -C '${PICFLAG} -DPIC' -F f '${PICFLAG} -DPIC -O' )
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/thread-patch && \
		${MAKE_ENV} ${MAKE} xconfig && \
		${ANSWER} | ./xconfig -c ${CC} -f ${FC} -m ${CC} -g ${CC} -x ${CC} -a THREADED && \
		${ANSWER} | ./xconfig -c ${CC} -f ${FC} -m ${CC} -g ${CC} -x ${CC} -a THREADED_PIC -C '${PICFLAG} -DPIC' -F f '${PICFLAG} -DPIC -O' )

ATLAS_LIBS1=libalapack libatlas libcblas libf77blas libtstatlas
ATLAS_LIBS2=libptcblas libptf77blas
do-build:
# make lapack
.if ! exists(${WRKDIR}/lapack/Makefile)
	@${ECHO_MSG} "===>  Extracting lapack sub project"
	@${MKDIR} ${WRKDIR}/lapack
	@${CP} -r ${PORTSDIR}/math/lapack/files ${WRKDIR}/lapack
	@${CP} -r ${PORTSDIR}/math/lapack/scripts ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/Makefile ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/distinfo ${WRKDIR}/lapack
	@${CP} ${PORTSDIR}/math/lapack/pkg-descr ${WRKDIR}/lapack
	@cd ${WRKDIR}/lapack ; ${MAKE} "FFLAGS=${FFLAGS}" FC="${FC}" build WRKDIRPREFIX=""
.endif
	@(cd ${WRKSRC}; ${MAKE} ${.MAKEFLAGS} "ARCH=NON_THREADED_PIC" install arch=NON_THREADED_PIC)
	@(cd ${WRKSRC}; ${MAKE} ${.MAKEFLAGS} "ARCH=THREADED_PIC" install arch=THREADED_PIC)
.if defined(WITH_STATICLIB)
	@(cd ${WRKSRC}; ${MAKE} ${.MAKEFLAGS} "ARCH=NON_THREADED" install arch=NON_THREADED)
	@(cd ${WRKSRC}; ${MAKE} ${.MAKEFLAGS} "ARCH=THREADED" install arch=THREADED)
.endif

post-build:
.if defined(WITH_STATICLIB)
# make atlas enhanced lapack (static ver)
	(cd ${WRKSRC}; ${MKDIR} tmp1 ; \
		${CP} ${WRKDIR}/lapack/work/LAPACK/SRC/liblapack.a tmp1 ;\
		cd tmp1 ;\
		ar x liblapack.a ;\
		ar x ../lib/NON_THREADED/liblapack.a ;\
		ar r ../lib/NON_THREADED/libalapack.a *.o ;\
		ranlib ../lib/NON_THREADED/libalapack.a )
#  make atlas enhanced lapack (static and thread safe ver)
	(cd ${WRKSRC}; ${MKDIR} tmp2 ; \
		${CP} ${WRKDIR}/lapack/work/LAPACK/SRC/liblapack.a tmp2 ;\
		cd tmp2 ;\
		ar x liblapack.a ;\
		ar x ../lib/THREADED/liblapack.a ;\
		ar r ../lib/THREADED/libalapack.a *.o ;\
		ranlib ../lib/THREADED/libalapack.a )
.endif
# make atlas enhanced lapack (shared ver)
	( cd ${WRKSRC}; ${MKDIR} tmp3 ;\
	${TAR} --exclude "*.f" --exclude "*.po" --exclude "*.o"	-cf - -C ${WRKDIR}/lapack/work/LAPACK/SRC . | ${TAR} xf - -C tmp3 ;\
		for object in `${FIND} tmp3 -name "*.So"` ; do \
			n=`${ECHO_CMD} $${object}|${SED} -e 's#.So##'` ; \
			${MV} $$n.So $$n.o ; \
		done ; \
		cd tmp3 ;\
		ar x ../lib/NON_THREADED_PIC/liblapack.a ;\
		ar r ../lib/NON_THREADED_PIC/libalapack.a *.o ;\
		ranlib ../lib/NON_THREADED_PIC/libalapack.a )
# make atlas enhanced lapack (shared and thread safe ver)
	( cd ${WRKSRC}; ${MKDIR} tmp4 ;\
	${TAR} --exclude "*.f" --exclude "*.po" --exclude "*.o"	-cf - -C ${WRKDIR}/lapack/work/LAPACK/SRC . | ${TAR} xf - -C tmp4 ;\
		for object in `${FIND} tmp4 -name "*.So"` ; do \
			n=`${ECHO_CMD} $${object}|${SED} -e 's#.So##'` ; \
			${MV} $$n.So $$n.o ; \
		done ; \
		cd tmp4 ;\
		ar x ../lib/THREADED_PIC/liblapack.a ;\
		ar r ../lib/THREADED_PIC/libalapack.a *.o ;\
		ranlib ../lib/THREADED_PIC/libalapack.a )

# make atlas shared library
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/lib/NON_THREADED_PIC/ ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 --whole-archive ${i}.a )
.endfor

# make atlas shared (thread safe) library
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/lib/THREADED_PIC/ ; \
		ld -Bshareable -o ${i}_r.so.1 -x -soname ${i}_r.so.1 --whole-archive ${i}.a )
.endfor
.for i in ${ATLAS_LIBS2}
	( cd ${WRKSRC}/lib/THREADED_PIC/ ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 --whole-archive ${i}.a )
.endfor

do-install:
.for i in ${ATLAS_LIBS1}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/lib/NON_THREADED/${i}.a       ${PREFIX}/lib
.endif
	@${INSTALL_DATA} ${WRKSRC}/lib/NON_THREADED_PIC/${i}.so.1    ${PREFIX}/lib
	@${LN} -sf ${i}.so.1 ${PREFIX}/lib/${i}.so
.endfor
.for i in ${ATLAS_LIBS1}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED/${i}.a       ${PREFIX}/lib/${i}_r.a
.endif
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED_PIC/${i}_r.so.1    ${PREFIX}/lib/${i}_r.so.1
	@${LN} -sf ${i}_r.so.1 ${PREFIX}/lib/${i}_r.so
.endfor
.for i in ${ATLAS_LIBS2}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED/${i}.a       ${PREFIX}/lib
.endif
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED_PIC/${i}.so.1    ${PREFIX}/lib
	@${LN} -sf ${i}.so.1 ${PREFIX}/lib/${i}.so
.endfor
	@${INSTALL_DATA} ${WRKSRC}/include/cblas.h   ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/clapack.h ${PREFIX}/include
	@${INSTALL_DATA} ${FILESDIR}/blas.h    ${PREFIX}/include
	@${INSTALL_DATA} ${FILESDIR}/lapack.h  ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
