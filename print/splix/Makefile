# Ports collection makefile for:	splix
# Date created:				2007-03-30
# Whom:					Tomas Verbaitis <tomasv@megalogika.lt>
#
# $FreeBSD$
#

PORTNAME=	splix
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	tomasv@megalogika.lt
COMMENT=	A set of CUPS printer drivers for Samsung Printer Language printers

LIB_DEPENDS=	jbig:${PORTSDIR}/graphics/jbigkit
BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-base \
				ppdc:${PORTSDIR}/print/cupsddk
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_BZIP2=	yes

MODELS=			DELL SAMSUNG XEROX
PPD_DELL=		1100 1110
PPD_SAMSUNG=	clp200 clp300 clp500 clp510 clp600 clp610 clx2170 clx3160 \
				ml1510 ml1520 ml1610 ml1630 ml1710 ml1740 ml1750 ml2010 \
				ml2150 ml2250 ml2510 ml2550 ml3050 ml3560
PPD_XEROX=		ph3115 ph3116 ph3117 ph3120 ph3121 ph3122 ph3130 ph3150 \
				ph3420 ph3425 ph5500 ph6100 ph6110

FILTER_FILE=		rastertospl2
CUPS_CONFIG=		${PREFIX}/bin/cups-config
BIN_DEST_DIR=		`${CUPS_CONFIG} --serverbin | ${SED} \
					's|${LOCALBASE}|${PREFIX}|'`/filter
CUPS_DATA_DIR=		`${CUPS_CONFIG} --datadir | ${SED} \
					's|${LOCALBASE}|${PREFIX}|'`
DEST_DIR_DELL=		${CUPS_DATA_DIR}/model/dell
DEST_DIR_SAMSUNG=	${CUPS_DATA_DIR}/model/samsung
DEST_DIR_XEROX=		${CUPS_DATA_DIR}/model/xerox

do-install:

.for MODEL in ${MODELS}
	${MKDIR} ${DEST_DIR_${MODEL}}
.for PPD in $(PPD_${MODEL})
		${INSTALL_DATA} ${WRKSRC}/ppd/${PPD}.ppd $(DEST_DIR_${MODEL})
.endfor
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILTER_FILE} ${BIN_DEST_DIR}

.include <bsd.port.mk>
