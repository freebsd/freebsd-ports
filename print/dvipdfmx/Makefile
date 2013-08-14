# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	dvipdfmx
PORTVERSION=	20110311
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		http://project.ktug.or.kr/dvipdfmx/snapshot/latest/ \
		http://project.ktug.or.kr/dvipdfmx/snapshot/archive/
MASTER_SITE_SUBDIR=	dviware/dvipdfmx
DIST_SUBDIR=	dvipdfmx

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps

USE_TEX=	tetex base texmf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/share

PLIST_SUB=	DVIPDFMXDIR=${DVIPDFMXDIR} \
		FONTMAPDIR=${FONTMAPDIR} \
		GLYPHMAPDIR=${GLYPHMAPDIR} \
		FONTCMAPDIR=${FONTCMAPDIR} \
		MKTEXLSR=${MKTEXLSR} \
		ADOBECMAPDIR=${ADOBECMAPDIR}

MAN1=		extractbb.1

DVIPDFMXDIR=	${TEXMFDIR}/dvipdfmx
FONTMAPDIR=	${TEXMFDIR}/fonts/map/dvipdfmx
GLYPHMAPDIR=	${TEXMFDIR}/fonts/map/glyphlist
FONTCMAPDIR=	${TEXMFDIR}/fonts/cmap
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

post-install:
	${MKDIR} ${LOCALBASE}/${FONTCMAPDIR}
	${LN} -s -f ${ADOBECMAPDIR} \
		${LOCALBASE}/${FONTCMAPDIR}/adobe-cmaps
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
