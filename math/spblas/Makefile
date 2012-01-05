# ex:ts=8
# Ports collection makefile for:	spblas
# Date created:			5 January 2012
# Whom:				bf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	spblas
DISTVERSION=	1_02
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/spblas/:1 LOCAL/bf/:1 NL/blas/blast-forum/:2
DISTNAME=	nist_spblas_${DISTVERSION}
.ifndef(NOPORTDOCS) || make(makesum)
DISTFILES=	${EXTRACT_ONLY}:1 blas-report.pdf:2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf@FreeBSD.org
COMMENT=	NIST Sparse Basic Linear Algebra Subprograms (BLAS)

USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes
USE_ZIP=	yes

HEADERS=	blas_enum.h blas_sparse.h blas_sparse_proto.h
HDIR =		include/spblas
MAKE_ENV=	LIB=spblas SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF="${NONEXISTENT}" SRCS="${SRCS}"

NO_WRKSUBDIR=	yes
OPTIONS=	PROFILE "Build and install a profiling library" Off

PLIST_DIRS=	${HDIR}
PLIST_FILES=	${HEADERS:S|^|${HDIR}/|} lib/libspblas.a lib/libspblas.so \
		lib/libspblas.so.${SHLIB_MAJOR}

SHLIB_MAJOR=	1
SRCS=		nist_spblas.cc

.include <bsd.port.options.mk>

.if defined(WITH_PROFILE)
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE  =	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libspblas_p.a
.else
MAKE_ENV+=	NO_PROFILE=yes
.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	blas-report.pdf
.endif

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	${SRCS}
.endif

post-extract:
	@${PRINTF} "LIBDIR=\t${PREFIX}/lib\n.include <bsd.lib.mk>\n" > \
		${WRKSRC}/Makefile

post-install:
	@${INSTALL_DATA} -d ${PREFIX}/${HDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${HEADERS} ${PREFIX}/${HDIR}
.ifndef(NOPORTDOCS)
	@${INSTALL_DATA} -d ${DOCSDIR}
	@${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	@${INSTALL_DATA} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
