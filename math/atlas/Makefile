# New ports collection makefile for:	atlas
# Date created:		12 February 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

# NOTE: This port purposely ignores the CC and CFLAGS settings.
#       Program and compiler flags are finetuned to gcc 2.95/3.1.

PORTNAME=	atlas
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

LIB_DEPENDS=    lapack:${PORTSDIR}/math/lapack

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
INSTALLS_SHLIB= yes
USE_REINPLACE=  yes

.if (${MACHINE_ARCH} == "alpha")
USE_GCC=	3.1
.endif

do-configure:
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config < ${FILESDIR}/answer)
.else
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config)
.endif
.if (${MACHINE_ARCH} == "alpha")
	@(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/alpha-patch)
.endif

do-build:
.if (${MACHINE_ARCH} == "alpha") || defined(USE_GCC)
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|g;' ${WRKSRC}/Make.`cat ${WRKSRC}/ARCHNAME`
.endif
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=`cat ${WRKSRC}/ARCHNAME`)
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} sanity_test arch=`cat ${WRKSRC}/ARCHNAME`)
	(cd ${WRKSRC}; ${MKDIR} tmp ; \
		${CP} ${LOCALBASE}/lib/liblapack.a tmp ;\
		cd tmp ;\
		ar x liblapack.a ;\
		ar x ../lib/`cat ${WRKSRC}/ARCHNAME`/liblapack.a ;\
		ar r ../lib/`cat ${WRKSRC}/ARCHNAME`/libalapack.a *.o ;\
		ranlib ../lib/`cat ${WRKSRC}/ARCHNAME`/libalapack.a )
.for i in libatlas libcblas libf77blas libtstatlas libalapack
	( cd ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/ ; \
		ld -Bshareable -o ${i}.so.1 -x -soname ${i}.so.1 --whole-archive ${i}.a )
.endfor

do-install:
.for i in libatlas libcblas libf77blas libtstatlas libalapack
	@${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/${i}.a       ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/${i}.so.1    ${PREFIX}/lib
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
