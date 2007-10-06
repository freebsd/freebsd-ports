# New ports collection makefile for:	UMFPACK
# Date created:		5 Nov 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	umfpack
PORTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/umfpack/v${PORTVERSION}/
DISTNAME=	UMFPACKv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unsymmetric-pattern MultiFrontal Package

USE_FORTRAN=	yes
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

CONFLICTS=	suitesparse-2*

WRKSRC=		${WRKDIR}/${DISTNAME}/UMFPACK
ALL_TARGET=	lib

DEPRECATED=	Outdated subset of math/suitesparse
EXPIRATION_DATE=2007-11-30

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-extract:
	${CP}	${WRKDIR}/${DISTNAME}/AMD/Make/Make.linux	\
		${WRKDIR}/${DISTNAME}/AMD/Make/Make.freebsd

pre-build:
	@${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ;	\
	s+%%CFLAGS%%+${CFLAGS}+ ;		\
	s+%%LOCALBASE%%+${LOCALBASE}+ ;		\
	s+%%GCCLIBDIR%%+${GCCLIBDIR}+ ;         \
	s+%%FORTRANLIBS%%+${FORTRANLIBS}+ ;         \
	s+%%BLAS%%+${BLAS}+ ;'	\
	 ${WRKDIR}/${DISTNAME}/AMD/Make/Make.freebsd

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Lib/libamd.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Lib/libumfpack.a ${PREFIX}/lib
.for mod in AMD UMFPACK
	@${MKDIR} ${PREFIX}/include/${mod}
	@for inc in `${LS} ${WRKSRC}/../${mod}/Include` ; do \
		${INSTALL_DATA} ${WRKSRC}/../${mod}/Include/$$inc ${PREFIX}/include/${mod}; \
	done
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Doc/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/Doc/*.pdf  ${DOCSDIR}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} --exclude tmp -C ${WRKSRC}/Demo -cf - . | \
		${TAR} -C ${EXAMPLESDIR} -xf -
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.if defined(MAINTAINER_MODE)
regression-test:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} hb )
.endif

.include <bsd.port.post.mk>
