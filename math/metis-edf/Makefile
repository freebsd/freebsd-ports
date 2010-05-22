# New ports collection makefile for:	metis-edf
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	metis-edf
DISTVERSIONPREFIX=	full-src-
DISTVERSION=	4.1-2
DISTVERSIONSUFFIX=	.noarch
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meshes partionning tool used by Code_Aster

CONFLICTS=	metis-[0-9]*

ASTER_VER=	10.1.0
ASTER_DISTVERSION=	${ASTER_VER}-4
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

ALL_TARGET=	default
MAKE_ENV+=	AR="${AR}" PICFLAG="${PICFLAG}"
MAKE_JOBS_UNSAFE=	yes
REINPLACE_ARGS=	-i ""

USE_FORTRAN=	yes
USE_LDCONFIG=	yes
FFLAGS+=	-O2
PICFLAG?=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME:C/-/_/}-${PORTVERSION:R}

PROGS=		kmetis onmetis.exe pmetis
DOCS=		CHANGES Doc/manual.ps README_Code_Aster

MACHINEARCH=	${ARCH}
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME:C/-/_/}-${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-configure:
.if ${MACHINEARCH} != "i386"
	${FIND} ${WRKSRC} -type f -name "*.c" -o -name "*.h" | ${XARGS}	\
		${REINPLACE_CMD} -e "s|long int|int|g"				\
			-e "s|long|int|g"					\
			-e "s|\(%[[:digit:]]\)ld|\1d|g"				\
			-e "s|\(%[[:digit:]]\.[[:digit:]]\)le|\1e|g"		\
			-e "s|%ld|%d|g"
.endif
	${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	${REINPLACE_CMD} -e 's|%%FORTRANLIBS%%|${FORTRANLIBS}|g' -e 's|%%GCCLIBDIR%%|${GCCLIBDIR}|g'\
		${WRKSRC}/Programs/Makefile
	${REINPLACE_CMD} -e 's|$$prefix|${PREFIX}/bin|' ${WRKSRC}/CONFIG/onmetis.in
	${REINPLACE_CMD} -e 's|$$prefix|${WRKSRC}|' ${WRKSRC}/onmetis

do-install:
	${MKDIR} ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h    ${PREFIX}/include/metis
	${CP} ${WRKSRC}/CONFIG/onmetis.in ${WRKSRC}/onmetis
	${REINPLACE_CMD} -e "s#HOME_METIS#${PREFIX}/bin#" ${WRKSRC}/onmetis
	${INSTALL_SCRIPT} ${WRKSRC}/onmetis ${PREFIX}/bin
	${REINPLACE_CMD} -e 's|${WRKSRC}|${PREFIX}/bin|' ${PREFIX}/bin/onmetis
	${INSTALL_PROGRAM} ${PROGS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${WRKSRC}/libmetis.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libmetis.so.1 ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for df in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${df} ${DOCSDIR}
. endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Test/fort.81 ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Test file installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
