# New ports collection makefile for:	metis-edf
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	metis-edf
DISTVERSION=	4.0-3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-${DISTVERSION}.noarch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meshes partionning tool used by Code_Aster

CONFLICTS=	metis-[0-9]*

ALL_TARGET=	default
MAKE_ENV+=	AR="${AR}"
REINPLACE_ARGS=	-i ""

USE_FORTRAN=	yes
FFLAGS+=	-O2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PROGS=		kmetis onmetis.exe pmetis

MACHINEARCH=	${ARCH}
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.include <bsd.port.pre.mk>

pre-configure:
.if ${MACHINEARCH} != "i386"
	@${FIND} ${WRKSRC} -type f -name "*.c" -o -name "*.h" | ${XARGS}	\
		${REINPLACE_CMD} -e "s|long int|int|g"				\
			-e "s|long|int|g"					\
			-e "s|\(%[[:digit:]]\)ld|\1d|g"				\
			-e "s|\(%[[:digit:]]\.[[:digit:]]\)le|\1e|g"		\
			-e "s|%ld|%d|g"
.endif
	@${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} -e 's|%%FORTRANLIBS%%|${FORTRANLIBS}|g' -e 's|%%GCCLIBDIR%%|${GCCLIBDIR}|g' ${WRKSRC}/Programs/Makefile

do-install:
	@${CP} ${WRKSRC}/CONFIG/onmetis.in ${WRKSRC}/onmetis
	@${REINPLACE_CMD} -e "s#HOME_METIS#${PREFIX}/bin#" ${WRKSRC}/onmetis
	${INSTALL_SCRIPT} ${WRKSRC}/onmetis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${PROGS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Test/fort.81 ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Test file installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
