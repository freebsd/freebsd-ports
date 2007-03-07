# New ports collection makefile for:	atlas-devel
# Date created:		14 September 2003
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc.

PORTNAME=	atlas
PORTVERSION=	3.7.29
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Development version of math/atlas

NO_PACKAGE=	Optimizes for the local machine, so a package is not generally useful.  Set FORCE_PACKAGE to override

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/ATLAS
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=	alpha

#to compile the ATLAS kernel we use gcc3. See ATLAS/INSTALL.txt for details.
WANT_FORTRAN=	yes
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=	gfortran42
F77=	gfortran42
.if ${OSVERSION} > 700000
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
CCOMPILER=	gcc34
.else
CCOMPILER=	${CC}
.endif
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

# only affects for lapack sub project
.if defined(WITH_OPTIMIZED_FLAGS)
.if defined(CPUTYPE)
FFLAGS+=	-mtune=${CPUTYPE} -pipe -O2 -ffast-math
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
.if !defined(WITH_STATICLIB)
	@${ECHO_MSG} "You can build static libraries with"
	@${ECHO_MSG} "make -DWITH_STATICLIB"
	@${ECHO_MSG}
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|%%CC%%|${CCOMPILER}|g" \
		-e "s|%%FC%%|${FC}|g"  ${WRKSRC}/CONFIG/src/atlcomp.txt
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
			  -e "s|%%PTHREAD_LIBS%%|${PTHREAD_CFLAGS}|g" \
			  -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/CONFIG/src/SpewMakeInc.c

do-configure:
#non threaded
#dummy f77lib, it is not used.
	${MKDIR} ${WRKSRC}/NON_THREADED ; cd ${WRKSRC}/NON_THREADED ; \
		../configure -t 0 -Si cputhrchk 0 -Ss f77lib " "
	${MKDIR} ${WRKSRC}/NON_THREADED_PIC ; cd ${WRKSRC}/NON_THREADED_PIC ; \
		../configure -t 0 -Fag al '${PICFLAG} -DPIC' -Si cputhrchk 0 -Ss f77lib " "
#threaded
#dummy f77lib, it is not used.
	cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/thread-patch
	${MKDIR} ${WRKSRC}/THREADED ; cd ${WRKSRC}/THREADED ; \
		../configure -Fag al '${PTHREAD_CFLAGS} ' -Si cputhrchk 0 -Ss f77lib " "
	${MKDIR} ${WRKSRC}/THREADED_PIC ; cd ${WRKSRC}/THREADED_PIC ; \
		../configure -Fag al '${PTHREAD_CFLAGS} ${PICFLAG} -DPIC' -Si cputhrchk 0 -Ss f77lib " "

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
.if defined(WITH_STATICLIB)
	(cd ${WRKSRC}/NON_THREADED ; ${MAKE})
	(cd ${WRKSRC}/THREADED ; ${MAKE})
.endif
	(cd ${WRKSRC}/NON_THREADED_PIC ; ${MAKE})
	(cd ${WRKSRC}/THREADED_PIC ; ${MAKE})
	@${MAKE} test

ATLAS_LIBS1=libalapack libatlas libcblas libf77blas #libtstatlas
ATLAS_LIBS2=libptcblas libptf77blas

post-build:
.if defined(WITH_STATICLIB)
# make atlas enhanced lapack (static ver)
	(cd ${WRKSRC}; ${MKDIR} tmp1 ; \
		${CP} ${WRKDIR}/lapack/work/LAPACK/SRC/liblapack.a tmp1 ;\
		cd tmp1 ;\
		ar x liblapack.a ;\
		ar x ../NON_THREADED/lib/liblapack.a ;\
		ar r ../NON_THREADED/lib/libalapack.a *.o ;\
		ranlib ../NON_THREADED/lib/libalapack.a )
#  make atlas enhanced lapack (static and thread safe ver)
	(cd ${WRKSRC}; ${MKDIR} tmp2 ; \
		${CP} ${WRKDIR}/lapack/work/LAPACK/SRC/liblapack.a tmp2 ;\
		cd tmp2 ;\
		ar x liblapack.a ;\
		ar x ../THREADED/lib/liblapack.a ;\
		ar r ../THREADED/lib/libalapack.a *.o ;\
		ranlib ../THREADED/lib/libalapack.a )
.endif
# make atlas enhanced lapack (shared ver)
	( cd ${WRKSRC}; ${MKDIR} tmp3 ;\
	${TAR} --exclude "*.f" --exclude "*.po" --exclude "*.o"	-cf - -C ${WRKDIR}/lapack/work/LAPACK/SRC . | ${TAR} xf - -C tmp3 ;\
		for object in `${FIND} tmp3 -name "*.So"` ; do \
			n=`${ECHO_CMD} $${object}|${SED} -e 's#.So##'` ; \
			${MV} $$n.So $$n.o ; \
		done ; \
		cd tmp3 ;\
		ar x ../NON_THREADED_PIC/lib/liblapack.a ;\
		ar r ../NON_THREADED_PIC/lib/libalapack.a *.o ;\
		ranlib ../NON_THREADED_PIC/lib/libalapack.a )
# make atlas enhanced lapack (shared and thread safe ver)
	( cd ${WRKSRC}; ${MKDIR} tmp4 ;\
	${TAR} --exclude "*.f" --exclude "*.po" --exclude "*.o"	-cf - -C ${WRKDIR}/lapack/work/LAPACK/SRC . | ${TAR} xf - -C tmp4 ;\
		for object in `${FIND} tmp4 -name "*.So"` ; do \
			n=`${ECHO_CMD} $${object}|${SED} -e 's#.So##'` ; \
			${MV} $$n.So $$n.o ; \
		done ; \
		cd tmp4 ;\
		ar x ../THREADED_PIC/lib/liblapack.a ;\
		ar r ../THREADED_PIC/lib/libalapack.a *.o ;\
		ranlib ../THREADED_PIC/lib/libalapack.a )

# make atlas shared library
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/NON_THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}.so.2 -x -soname ${i}.so.2 --whole-archive ${i}.a )
.endfor

# make atlas shared (thread safe) library
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
	@${INSTALL_DATA} ${FILESDIR}/blas.h    ${PREFIX}/include
	@${INSTALL_DATA} ${FILESDIR}/lapack.h  ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	@for i in ${ALLTESTS} ; do \
	cd ${WRKDIR}/ATLAS/NON_THREADED_PIC/bin ; ${INSTALL_PROGRAM} $${i} ${EXAMPLESDIR} ; \
	done
	@for i in ${ALLTESTS_PT} ; do \
	cd ${WRKDIR}/ATLAS/THREADED_PIC/bin ; ${INSTALL_PROGRAM} $${i} ${EXAMPLESDIR} ; \
	done

.include <${FILESDIR}/Makefile.test>
.include <bsd.port.post.mk>
