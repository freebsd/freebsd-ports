# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	mol2ps
PORTVERSION=	0.4a
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://merian.pch.univie.ac.at/pch/download/chemistry/${PORTNAME}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pas
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read molecular structure files and generate Postscript output

LICENSE=	GPLv2 # (or later)

NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKDIR}

USE_FPC=	yes

PLIST_FILES=	bin/${PORTNAME} bin/mol2svg %%DATADIR%%/color.conf
PLIST_DIRS=	%%DATADIR%%

do-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/fpc ${EXTRACT_ONLY} -S2 -O3)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} ${PORTNAME} mol2svg)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${FILESDIR} && ${INSTALL_DATA} color.conf ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
