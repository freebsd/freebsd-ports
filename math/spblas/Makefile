# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	spblas
DISTVERSION=	1_02
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/spblas/:1 LOCAL/bf/:1 NL/blas/blast-forum/:2
DISTFILES=	nist_spblas_${DISTVERSION}.zip:1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NIST Sparse Basic Linear Algebra Subprograms (BLAS)

USES=		dos2unix uidfix zip
USE_GCC=	yes
USE_LDCONFIG=	yes

HEADERS=	blas_enum.h blas_sparse.h blas_sparse_proto.h
HDIR=		include/spblas
MAKE_ENV=	LIB=spblas SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF=/dev/null SRCS="${SRCS}"

NO_WRKSUBDIR=	yes
OPTIONS_DEFINE=	PROFILE DOCS EXAMPLES

PLIST_FILES=	${HEADERS:S|^|${HDIR}/|} lib/libspblas.a lib/libspblas.so \
		lib/libspblas.so.${SHLIB_MAJOR}

SHLIB_MAJOR=	1
SRCS=		nist_spblas.cc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE=		you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=		you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libspblas_p.a
.else
MAKE_ENV+=	NO_PROFILE=yes
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	blas-report.pdf
.endif

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	blas-report.pdf:2
EXTRACT_ONLY=	nist_spblas_${DISTVERSION}.zip
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	${SRCS}
.endif

post-extract:
	@${PRINTF} "LIBDIR=\t${PREFIX}/lib\n.include <bsd.lib.mk>\n" > \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${HDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${HEADERS} ${STAGEDIR}${PREFIX}/${HDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
