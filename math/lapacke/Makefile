# New ports collection makefile for:    lapacke
# Date created: 17 Feb 2011
# Whom:         Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	lapacke
PORTVERSION=	1.0.0.009
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	lapack
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Standard C language APIs for LAPACK

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_FORTRAN=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	PROFILE "Build a profiling library" Off

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}

.if exists(${LOCALBASE}/lib/libgoto2p.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "reference"
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == "gotoblas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	goto2p.1:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
WITHOUT_LAPACK_LATEST=	yes
.elif ${WITH_BLAS} == "atlas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas -lptcblas -latlas
LAPACK=		-lalapack
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
.if defined(WITHOUT_LAPACK_LATEST)
MAKE_ENV+=	WITHOUT_LAPACK_LATEST=yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif
PLIST_FILES=	include/lapacke.h \
		include/lapacke_utils.h \
		lib/liblapacke.a \
		lib/liblapacke.so \
		lib/liblapacke.so.1

.if defined(WITH_PROFILE)
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE	=	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/liblapacke_p.a
.else
MAKE_ENV+=	NO_PROFILE=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's;%%CC%%;${CC};g' \
			  -e 's;%%CFLAGS%%;${CFLAGS};g' \
			  -e 's;%%LDFLAGS%%;${LDFLAGS};g' \
			  -e 's;%%AR%%;${AR};g' \
			  -e 's;%%RANLIB%%;${RANLIB};g' \
			  -e 's;%%BLAS%%;${BLAS};g' \
			  -e 's;%%LAPACK%%;${LAPACK};g' \
				${WRKSRC}/make.inc
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${MKDIR} ${WRKSRC}/lib
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/lib/Makefile

post-build:
.if !defined(WITHOUT_TESTING)
	@${ECHO_CMD} "Testing static lapacke library"
	@(cd ${WRKSRC}/testing; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS})
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
