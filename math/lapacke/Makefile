# New ports collection makefile for:    lapacke
# Date created: 17 Feb 2011
# Whom:         Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	lapacke
PORTVERSION=	1.0.0.009
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/ \
		http://netlib.org/lapack/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Standard C language APIs for LAPACK

#LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}

.if exists(${LOCALBASE}/lib/libgoto2p.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "reference"
LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == "gotoblas"
LIB_DEPENDS=	goto2:${PORTSDIR}/math/gotoblas
BLAS=		-lpthread -lgoto2p
LAPACK=		-lpthread -lgoto2p
WITHOUT_LAPACK_LATEST=	yes
.elif ${WITH_BLAS} == "atlas"
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lpthread -lptf77blas -lptcblas -latlas_r
LAPACK=		-lpthread -lalapack_r
.endif

LDFLAGS+=	-L${LOCALBASE}/lib -lgfortran -lgcc_s
LDADD?=		-lgfortran -lgcc_s
MAKE_ENV=	LDADD="${LDADD}" LDFLAGS="${LDFLAGS}"
.if defined(WITHOUT_LAPACK_LATEST)
MAKE_ENV+=	WITHOUT_LAPACK_LATEST=yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README \
		LICENSE
.endif
PLIST_FILES=	include/lapacke.h \
		include/lapacke_utils.h \
		lib/liblapacke.a \
		lib/liblapacke.so \
		lib/liblapacke.so.1
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
PLIST_FILES+=	lib/liblapacke_p.a
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
