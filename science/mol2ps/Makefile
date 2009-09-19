# New ports collection makefile for:	mol2ps
# Date created:		23 Feb 2009
# Whom:	      		Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	mol2ps
PORTVERSION=	0.1e
CATEGORIES=	science
MASTER_SITES=	http://merian.pch.univie.ac.at/pch/download/chemistry/${PORTNAME}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pas

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Read molecular structure files and generate Postscript output

USE_FPC=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/
do-build:
	cd ${WRKDIR}; ${LOCALBASE}/bin/fpc ${DISTFILES} -S2 -O3 -Op3
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/color.conf ${DATADIR}

.include <bsd.port.mk>
