# New ports collection makefile for:	atlas-devel
# Date created:		14 September 2003
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc.

PORTNAME=	atlas
PORTVERSION=	3.7.24
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

NOT_FOR_ARCHS=	alpha
#GCC4 produces slower code...
USE_GCC=	3.2+

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

# only affects for lapack sub project
.if defined(WITH_OPTIMIZED_FLAGS)
.if defined(CPUTYPE)
FFLAGS+=	-mtune=${CPUTYPE} -pipe -O2 -ffast-math -fomit-frame-pointer
.else
FFLAGS+=	-pipe -O2 -ffast-math -fomit-frame-pointer
.endif
.endif

.if defined(WITH_STATICLIB)
PLIST_SUB=      WITH_STATICLIB=""
.else
PLIST_SUB=      WITH_STATICLIB="@comment "
.endif

post-extract:
.if !defined(WITH_STATICLIB)
	@${ECHO_MSG} "You can build static libraries with"
	@${ECHO_MSG} "make -DWITH_STATICLIB"
	@${ECHO_MSG}
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|%%CC%%|${CC}|g" \
		-e "s|%%FC%%|${FC}|g"  ${WRKSRC}/CONFIG/src/atlcomp.txt
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		${WRKSRC}/CONFIG/src/SpewMakeInc.c

do-configure:
	${MKDIR} ${WRKSRC}/NON_THREADED ; cd ${WRKSRC}/NON_THREADED ; \
		../configure -t 0
	${MKDIR} ${WRKSRC}/THREADED ; cd ${WRKSRC}/THREADED ; \
		../configure -t 0  -Fa al '${PTHREAD_CFLAGS} '
	${MKDIR} ${WRKSRC}/NON_THREADED_PIC ; cd ${WRKSRC}/NON_THREADED_PIC ; \
		../configure -t -1 -Fa al '${PICFLAG} -DPIC'
	${MKDIR} ${WRKSRC}/THREADED_PIC ; cd ${WRKSRC}/THREADED_PIC ; \
		../configure -t -1 -Fa al '${PTHREAD_CFLAGS} ${PICFLAG} -DPIC'

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

ATLAS_LIBS=libalapack libatlas libcblas libf77blas libtstatlas

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
.for i in ${ATLAS_LIBS}
	( cd ${WRKSRC}/NON_THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 ${i}.a )
.endfor

# make atlas shared (thread safe) library
.for i in ${ATLAS_LIBS}
	( cd ${WRKSRC}/THREADED_PIC/lib ; \
		ld -Bshareable -o ${i}_r.so.1 -x -soname ${i}_r.so.1 ${i}.a )
.endfor

do-install:
.for i in ${ATLAS_LIBS}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/NON_THREADED/lib/${i}.a       ${PREFIX}/lib
.endif
	@${INSTALL_DATA} ${WRKSRC}/NON_THREADED_PIC/lib/${i}.so.1    ${PREFIX}/lib
	@${LN} -sf ${i}.so.1 ${PREFIX}/lib/${i}.so
.endfor
.for i in ${ATLAS_LIBS}
.if defined(WITH_STATICLIB)
	@${INSTALL_DATA} ${WRKSRC}/THREADED/lib/${i}.a       ${PREFIX}/lib/${i}_r.a
.endif
	@${INSTALL_DATA} ${WRKSRC}/THREADED_PIC/lib/${i}_r.so.1    ${PREFIX}/lib/${i}_r.so.1
	@${LN} -sf ${i}_r.so.1 ${PREFIX}/lib/${i}_r.so
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
