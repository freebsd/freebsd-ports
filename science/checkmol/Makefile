# New ports collection makefile for:	checkmol
# Date created:		23 Feb 2009
# Whom:	      		Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	checkmol
PORTVERSION=	0.4a
CATEGORIES=	science
MASTER_SITES=	http://merian.pch.univie.ac.at/pch/download/chemistry/checkmol/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pas

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Analyze molecules for the presence of functional groups

USE_FPC=	yes
PLIST_FILES=	bin/checkmol bin/matchmol

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/
do-build:
	cd ${WRKDIR}; ${LOCALBASE}/bin/fpc ${DISTFILES} -S2 -O3 -Op3
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	${LN} ${PREFIX}/bin/${PORTNAME} ${PREFIX}/bin/matchmol

.include <bsd.port.mk>
