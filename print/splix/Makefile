# Ports collection makefile for:	splix
# Date created:				2007-03-30
# Whom:					Tomas Verbaitis <tomasv@megalogika.lt>
#
# $FreeBSD$
#

PORTNAME=	splix
PORTVERSION=	1.0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tomasv@megalogika.lt
COMMENT=	A set of CUPS printer drivers for Samsung Printer Language printers

BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_BZIP2=	yes

PPD_FILES=	ml1510 ml1520 ml1610 ml1710 ml1740 ml1750 ml2010 ml2150 ml2250 \
		ml2550 clp300 clp500 clp510 clp600 xerox-phaser6100
FILTER_FILE=	rastertospl2
CUPS_CONFIG=	${PREFIX}/bin/cups-config
DATA_DEST_DIR=	`${CUPS_CONFIG} --datadir | ${SED} \
			's|${LOCALBASE}|${PREFIX}|'`/model/samsung
BIN_DEST_DIR=	`${CUPS_CONFIG} --serverbin | ${SED} \
			's|${LOCALBASE}|${PREFIX}|'`/filter

do-install:
	${MKDIR} ${DATA_DEST_DIR}
.for PPD in ${PPD_FILES}
	${INSTALL_DATA} ${WRKSRC}/ppd/${PPD}.ppd ${DATA_DEST_DIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILTER_FILE} ${BIN_DEST_DIR}

.include <bsd.port.mk>
