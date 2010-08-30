# New ports collection makefile for:    blas
# Date created:         27 October 1994
# Whom:                 ljo
#
# $FreeBSD$
#

PORTNAME=	blas
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/blas/ \
		http://www.mirrorservice.org/sites/netlib.bell-labs.com/netlib/blas/ \
		ftp://ftp.mirrorservice.org/sites/netlib.bell-labs.com/netlib/blas/ \
		http://netlib.sandia.gov/blas/ \
		http://www.netlib.no/netlib/blas/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Basic Linear Algebra, level 1, 2, and 3

USE_LDCONFIG=	yes
USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/BLAS
SHLIB_MAJOR=	2

PLIST_FILES=	lib/libblas.a lib/libblas.so lib/libblas.so.${SHLIB_MAJOR}

LDFLAGS+=	${FFLAGS}
LDADD ?=	-lgfortran -lm
MAKE_ENV+=	LDADD="${LDADD}" LDFLAGS="${LDFLAGS}" \
		SHLIB_MAJOR="${SHLIB_MAJOR}"
.for _u in AR NM RANLIB
MAKE_ENV+=	${_u}="${LOCALBASE}/bin/${_u:L}"
.endfor

.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
PLIST_FILES+=	lib/libblas_p.a
.endif

post-patch:
	@${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

.include <bsd.port.mk>
