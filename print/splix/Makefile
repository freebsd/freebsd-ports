# Ports collection makefile for:	splix
# Date created:				2007-03-30
# Whom:					Tomas Verbaitis <tomasv@megalogika.lt>
#
# $FreeBSD$
#

PORTNAME=	splix
PORTVERSION=	2.0.0
CATEGORIES?=	print
MASTER_SITES=	SF

MAINTAINER=	tomasv@megalogika.lt
COMMENT=	A set of CUPS printer drivers for Samsung Printer Language printers

LIB_DEPENDS=
BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-base \
		ppdc:${PORTSDIR}/print/cupsddk
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_BZIP2=	yes

MODELS=		DELL SAMSUNG XEROX
PPD_DELL=	1100 1110
PPD_SAMSUNG=	clp500 clp510 clp550 clp610 \
		ml1510 ml1520 ml1610 ml1630 ml1640 ml1710 ml1740 ml1750 \
		ml2010 ml2150 ml2250 ml2251 ml2510 ml2550 \
		ml3050 ml3560 \
		scx4200 scx4500
PPD_XEROX=	ph3115 ph3116 ph3117 ph3120 ph3121 ph3122 ph3130 ph3150 \
		ph3420 ph3425 ph5500 ph6100 wc3119 ph3160
PPD_SAMSUNG_JBIG=	clp200 clp300 clp600 clx216x clx2170 clx3160
PPD_XEROX_JBIG=		ph6110

FILTER_FILE=	rastertoqpdl pstoqpdl
CUPS_CONFIG=	${PREFIX}/bin/cups-config
BIN_DEST_DIR=	`${CUPS_CONFIG} --serverbin | ${SED} \
		's|${LOCALBASE}|${PREFIX}|'`/filter
CUPS_DATA_DIR=	`${CUPS_CONFIG} --datadir | ${SED} \
		's|${LOCALBASE}|${PREFIX}|'`
DEST_DIR_DELL=	${CUPS_DATA_DIR}/model/dell
DEST_DIR_SAMSUNG=	${CUPS_DATA_DIR}/model/samsung
DEST_DIR_XEROX=	${CUPS_DATA_DIR}/model/xerox

THREADS=	2
WITH_THREADS=	1

OPTIONS=	JBIG "Enable use of JBIG algorithm (pattented)" on \
		BLACKOPTIM "Enable black correction algorithm" on \

.include "bsd.port.options.mk"

.include "bsd.port.pre.mk"

post-configure:

.if !defined(WITHOUT_JBIG)
PPD_SAMSUNG+=	${PPD_SAMSUNG_JBIG}
PPD_XEROX+=	${PPD_XEROX_JBIG}
LIB_DEPENDS=	jbig:${PORTSDIR}/graphics/jbigkit
.endif

.if defined(WITHOUT_JBIG)
MAKE_ARGS+=	DISABLE_JBIG=1
.endif

.if defined(WITHOUT_BLACKOPTIM)
MAKE_ARGS+=	DISABLE_BLACKOPTIM=1
.endif

.if defined(CACHESIZE)
MAKE_ARGS+=	CACHESIZE=${CACHESIZE}
.endif

do-install:
.for MODEL in ${MODELS}
	${MKDIR} ${DEST_DIR_${MODEL}}
.for PPD in $(PPD_${MODEL})
	${INSTALL_DATA} ${WRKSRC}/ppd/${PPD}.ppd $(DEST_DIR_${MODEL})
.endfor
.endfor

.for FILTER in ${FILTER_FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/optimized/${FILTER} ${BIN_DEST_DIR}
.endfor

.include <bsd.port.post.mk>
