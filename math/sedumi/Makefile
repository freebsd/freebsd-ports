# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sedumi
PORTVERSION=    1.1
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/sedumi|}
# http://sedumi.mcmaster.ca/
DISTNAME=	SeDuMi_1_1R3

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SeDuMi is an semidefinite programming solver on Matlab

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave
BUILD_DEPENDS=	octave:${PORTSDIR}/math/octave

USES=		zip
WRKSRC=		${WRKDIR}/SeDuMi_1_1

NO_STAGE=	yes
pre-patch:
	@${LS} ${WRKSRC}/*.m ${WRKSRC}/*.c > ${WRKDIR}/FILELIST
	@for i in `${CAT} ${WRKDIR}/FILELIST`; do \
		cd ${WRKSRC} ; ${REINPLACE_CMD} -e 's###g' $$i ; \
	done
	@cd ${WRKSRC} ; ${RM} *.bak

pre-build:
	@cd ${WRKSRC} ; ${RM} *.dll *.orig

do-build:
	cd ${WRKSRC} ; octave install_sedumi.m
	@cd ${WRKSRC} ; ${RM} *.c *.o

do-install:
	${MKDIR} ${PREFIX}/sedumi
	${INSTALL_PROGRAM} ${WRKSRC}/*mex ${PREFIX}/sedumi
	${INSTALL_DATA} ${WRKSRC}/*m ${PREFIX}/sedumi
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.ifndef (NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.include <bsd.port.mk>
