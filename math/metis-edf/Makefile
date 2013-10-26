# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	metis-edf
DISTVERSION=	4.1-2
PORTREVISION=	4
CATEGORIES=	math

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Meshes partitioning tool used by Code_Aster

CONFLICTS=	metis-[0-9]*

ALL_TARGET=	default
MAKE_ENV+=	AR="${AR}" PICFLAG="${PICFLAG}"
MAKE_JOBS_UNSAFE=	yes
REINPLACE_ARGS=	-i ""

USE_FORTRAN=	yes
FFLAGS+=	-O2
PICFLAG?=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PROGS=		kmetis onmetis.exe pmetis
DOCS=		CHANGES Doc/manual.ps README_Code_Aster

FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

MACHINEARCH=	${ARCH}
.if ${ARCH} == "i386"
USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB=""
.else
PLIST_SUB+=	SHLIB="@comment "
.endif

pre-configure:
.if ${MACHINEARCH} != "i386"
	${FIND} ${WRKSRC} -type f -name "*.c" -o -name "*.h" | ${XARGS}	\
		${REINPLACE_CMD} -e "s|long int|int|g"				\
			-e "s|long|int|g"					\
			-e "s|\(%[[:digit:]]\)ld|\1d|g"				\
			-e "s|\(%[[:digit:]]\.[[:digit:]]\)le|\1e|g"		\
			-e "s|%ld|%d|g"
	${REINPLACE_CMD} -e 's|%%SHLIB%%|#|' ${WRKSRC}/Lib/Makefile
.else
	${REINPLACE_CMD} -e 's|%%SHLIB%%||' ${WRKSRC}/Lib/Makefile
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
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib
.if ${MACHINEARCH} == "i386"
	${INSTALL_DATA} ${WRKSRC}/libmetis.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libmetis.so.1 ${PREFIX}/lib
.endif

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

.include <bsd.port.post.mk>
