# New ports collection makefile for:	cm-super
# Date created:		27 June 2006
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	cm-super
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	print x11-fonts
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	hrs
#MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
#MASTER_SITE_SUBDIR=	fonts/ps-type1
#DISTNAME=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern Font Families in Type 1 Fonts

.if !defined(WITHOUT_X11)
BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst
.endif
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(WITHOUT_X11)
PLIST_X11=	""
.else
PLIST_X11=	"@comment "
.endif
PLIST_SUB=	PLIST_X11=${PLIST_X11} \
		UPDMAP_SYS="${UPDMAP_SYS}" \
		MAPFILES="${MAPFILES}" \
		MKTEXLSR="${MKTEXLSR}" \
		TEXMFDIR=${TEXMFDIR} \
		MACRODIR=${MACRODIR} \

UPDMAP_SYS=	${LOCALBASE}/bin/updmap-sys --quiet --progname=all
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
FONTSDIR=	share/fonts/${PORTNAME}
AFMDIR=		${TEXMFDIR}/fonts/afm/public/${PORTNAME}
TYPE1DIR=	${TEXMFDIR}/fonts/type1/public/${PORTNAME}
DVIPDFMMAPDIR=	${TEXMFDIR}/fonts/map/dvipdfm/${PORTNAME}
DVIPSENCDIR=	${TEXMFDIR}/fonts/enc/dvips/${PORTNAME}
DVIPSMAPDIR=	${TEXMFDIR}/fonts/map/dvips/${PORTNAME}
MACRODIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
MAPFILES=	cm-super-t1.map \
		cm-super-t2a.map \
		cm-super-t2b.map \
		cm-super-t2c.map \
		cm-super-ts1.map \
		cm-super-x2.map

do-build:
.if !defined(WITHOUT_X11)
	${TOUCH} ${WRKSRC}/pfb/fonts.dir
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog -quiet)
.else
	@${DO_NADA}
.endif

post-extract:
	${GZIP_CMD} -d ${WRKSRC}/afm/*.gz

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/${FONTSDIR}/afm
	${LN} -s -f ${PREFIX}/${FONTSDIR}/afm \
		${PREFIX}/${AFMDIR}
	${MKDIR} ${PREFIX}/${FONTSDIR}/type1
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${PREFIX}/${FONTSDIR}/type1
	${LN} -s -f ${PREFIX}/${FONTSDIR}/type1 \
		${PREFIX}/${TYPE1DIR}
	${MKDIR} ${PREFIX}/${DVIPSMAPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvips/*.map \
		${PREFIX}/${DVIPSMAPDIR}
	${MKDIR} ${PREFIX}/${DVIPSENCDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvips/*.enc \
		${PREFIX}/${DVIPSENCDIR}
	${MKDIR} ${PREFIX}/${DVIPDFMMAPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/dvipdfm/*.map \
		${PREFIX}/${DVIPDFMMAPDIR}
	${MKDIR} ${PREFIX}/${MACRODIR}
	${INSTALL_DATA} \
		${WRKSRC}/type1ec.sty \
		${PREFIX}/${MACRODIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${FONTSDIR}/
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}
.for F in ${MAPFILES}
	@${ECHO_CMD} "Adding $F..."
	@${UPDMAP_SYS} --nohash --nomkmap --enable Map=${F} || true
.endfor
	@${ECHO_CMD} "Regenerating mapfiles..."
	@${UPDMAP_SYS}

.include <bsd.port.mk>
