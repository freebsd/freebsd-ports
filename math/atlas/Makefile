# New ports collection makefile for:	atlas
# Date created:		12 February 2001
# Whom:			Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc 2.95/3.1.

PORTNAME=	atlas
PORTVERSION=	3.5.5
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=        Automatically Tuned Linear Algebra Software (ATLAS)

BUILD_DEPENDS=	${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/lapack

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
INSTALLS_SHLIB= yes
USE_REINPLACE=  yes

.if (${MACHINE_ARCH} == "alpha")
USE_GCC=	3.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+ ${PTHREAD_CFLAGS}+' \
		${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%+ ${PTHREAD_LIBS}+' \
		${WRKSRC}/config.c
.if (${MACHINE_ARCH} == "alpha")
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/alpha-patch)
.endif

do-configure:
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/non-thread-patch)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config < ${FILESDIR}/answer)
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/thread-patch)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config < ${FILESDIR}/answer)

NON_THREADED_ATLAS=`cat ${WRKSRC}/ARCHNAME-NON-THREADED`
THREADED_ATLAS=`cat ${WRKSRC}/ARCHNAME-THREADED`
ATLAS_LIBS1=libatlas libcblas libf77blas libtstatlas libalapack
ATLAS_LIBS2=libptcblas libptf77blas

post-configure:
.if (${MACHINE_ARCH} == "alpha") || defined(USE_GCC)
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|g;' ${WRKSRC}/Make.${NON_THREADED_ATLAS}
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|g;' ${WRKSRC}/Make.${THREADED_ATLAS}
.endif

do-build:
# non thread version
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=${NON_THREADED_ATLAS})
#	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} sanity_test arch=${NON_THREADED_ATLAS})
	(cd ${WRKSRC}; ${MKDIR} tmp ; \
		${CP} ${LOCALBASE}/lib/liblapack.a tmp ;\
		cd tmp ;\
		ar x liblapack.a ;\
		ar x ../lib/${NON_THREADED_ATLAS}/liblapack.a ;\
		ar r ../lib/${NON_THREADED_ATLAS}/libalapack.a *.o ;\
		ranlib ../lib/${NON_THREADED_ATLAS}/libalapack.a )
.for i in ${ATLAS_LIBS1}
	( cd ${WRKSRC}/lib/${NON_THREADED_ATLAS}/ ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 --whole-archive ${i}.a )
.endfor

# thread version
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=${THREADED_ATLAS})
#	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} sanity_test arch=${THREADED_ATLAS})
	(cd ${WRKSRC}; ${MKDIR} tmp2 ; \
		${CP} ${LOCALBASE}/lib/liblapack.a tmp2 ;\
		cd tmp2 ;\
		ar x liblapack.a ;\
		ar x ../lib/${THREADED_ATLAS}/liblapack.a ;\
		ar r ../lib/${THREADED_ATLAS}/libalapack.a *.o ;\
		ranlib ../lib/${THREADED_ATLAS}/libalapack.a )
.for i in ${ATLAS_LIBS1} ${ATLAS_LIBS2}
	( cd ${WRKSRC}/lib/${THREADED_ATLAS}/ ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 --whole-archive ${i}.a )
.endfor

do-install:
.for i in ${ATLAS_LIBS1}
	@${INSTALL_DATA} ${WRKSRC}/lib/${NON_THREADED_ATLAS}/${i}.a       ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/${NON_THREADED_ATLAS}/${i}.so.1    ${PREFIX}/lib
	@${LN} -sf ${i}.so.1 ${PREFIX}/lib/${i}.so
.endfor
.for i in ${ATLAS_LIBS1}
	@${INSTALL_DATA} ${WRKSRC}/lib/${THREADED_ATLAS}/${i}.a       ${PREFIX}/lib/${i}_r.a
	@${INSTALL_DATA} ${WRKSRC}/lib/${THREADED_ATLAS}/${i}.so.1    ${PREFIX}/lib/${i}_r.so.1
	@${LN} -sf ${i}_r.so.1 ${PREFIX}/lib/${i}_r.so
.endfor
.for i in ${ATLAS_LIBS2}
	@${INSTALL_DATA} ${WRKSRC}/lib/${THREADED_ATLAS}/${i}.a       ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/${THREADED_ATLAS}/${i}.so.1    ${PREFIX}/lib
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

.include <bsd.port.mk>
