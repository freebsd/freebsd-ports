# New ports collection makefile for:	atlas-devel
# Date created:		14 September 2003
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc.

PORTNAME=	atlas
PORTVERSION=	3.7.8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Development version of math/atlas

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
NO_PACKAGE=	runtime performance heavily depends on building environment

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501000 && ${ARCH} == "alpha"
USE_GCC=3.3
.endif

# only affects for lapack sub project
.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=-pipe -O3 -ffast-math -finline-functions -fstrength-reduce -funroll-loops -fexpensive-optimizations
.if (${MACHINE_ARCH} == "i386" && !${MACHINE_ARCH} == "amd64" )
FFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
.endif # i386
.endif

post-patch:
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO_CMD} "You can optimize lapack sub project by setting WITH_OPTIMIZED_FLAGS=yes."
.endif
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g' \
			  -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g' \
		${WRKSRC}/config.c
.if (${MACHINE_ARCH} == "alpha")
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/alpha-patch)
.endif

PICFLAG!=	${MAKE} -f bsd.lib.mk -V PICFLAG

ANSWER_i386?=	${PRINTF} "\n\n\n\n\n\n\n\n\n\n"
ANSWER_ia64?=	${PRINTF} "\n\n\n2\n\n\n\n\nf77\n-O2 -static\n\n"

.if !defined(ANSWER_${ARCH})
ANSWER=	${ANSWER_i386}
.else
ANSWER=	${ANSWER_${ARCH}}
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
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=NON_THREADED)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=NON_THREADED_PIC)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=THREADED)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=THREADED_PIC)
post-build:
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
	@${INSTALL_DATA} ${WRKSRC}/lib/NON_THREADED/${i}.a       ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/NON_THREADED_PIC/${i}.so.1    ${PREFIX}/lib
	@${LN} -sf ${i}.so.1 ${PREFIX}/lib/${i}.so
.endfor
.for i in ${ATLAS_LIBS1}
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED/${i}.a       ${PREFIX}/lib/${i}_r.a
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED_PIC/${i}_r.so.1    ${PREFIX}/lib/${i}_r.so.1
	@${LN} -sf ${i}_r.so.1 ${PREFIX}/lib/${i}_r.so
.endfor
.for i in ${ATLAS_LIBS2}
	@${INSTALL_DATA} ${WRKSRC}/lib/THREADED/${i}.a       ${PREFIX}/lib
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
