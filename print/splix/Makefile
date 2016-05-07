# $FreeBSD$

PORTNAME=	splix
PORTVERSION=	2.0.0
PORTREVISION=	8
CATEGORIES?=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CUPS printer drivers for Samsung Printer Language printers

LIB_DEPENDS=	libcupsimage.so:print/cups

USES=		gmake tar:bzip2

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
CUPS_CONFIG=	${LOCALBASE}/bin/cups-config
BIN_DEST_DIR=	`${CUPS_CONFIG} --serverbin | ${SED} \
		's|${LOCALBASE}|${PREFIX}|'`/filter
CUPS_DATA_DIR=	`${CUPS_CONFIG} --datadir | ${SED} \
		's|${LOCALBASE}|${PREFIX}|'`
DEST_DIR_DELL=	${CUPS_DATA_DIR}/model/dell
DEST_DIR_SAMSUNG=	${CUPS_DATA_DIR}/model/samsung
DEST_DIR_XEROX=	${CUPS_DATA_DIR}/model/xerox

OPTIONS_DEFINE=	JBIG BLACKOPTIM
JBIG_DESC=	Enable use of JBIG algorithm (pattented)
BLACKOPTIM_DESC=	Enable black correction algorithm
OPTIONS_DEFAULT=	JBIG BLACKOPTIM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJBIG}
PPD_SAMSUNG+=	${PPD_SAMSUNG_JBIG}
PPD_XEROX+=	${PPD_XEROX_JBIG}
LIB_DEPENDS+=	libjbig.so:graphics/jbigkit
.else
MAKE_ARGS+=	DISABLE_JBIG=1
.endif

.if empty(PORT_OPTIONS:MBLACKOPTIM)
MAKE_ARGS+=	DISABLE_BLACKOPTIM=1
.endif

.if defined(CACHESIZE)
MAKE_ARGS+=	CACHESIZE=${CACHESIZE}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CC.*:= gcc/d' -e '/^CXX.*:= g++/d' \
		-e 's/make/$$(MAKE)/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} '/cups-config --libs/s/$$/ -pthread/' \
		${WRKSRC}/module.mk
	@${REINPLACE_CMD} 's/g++/$$(CXX)/' ${WRKSRC}/rules.mk

do-install:
	${MKDIR} ${STAGEDIR}${BIN_DEST_DIR}
.for MODEL in ${MODELS}
	${MKDIR} ${STAGEDIR}${DEST_DIR_${MODEL}}
.for PPD in $(PPD_${MODEL})
	${INSTALL_DATA} ${WRKSRC}/ppd/${PPD}.ppd ${STAGEDIR}$(DEST_DIR_${MODEL})
.endfor
.endfor

.for FILTER in ${FILTER_FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/optimized/${FILTER} ${STAGEDIR}${BIN_DEST_DIR}
.endfor

.include <bsd.port.mk>
