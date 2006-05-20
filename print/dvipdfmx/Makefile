# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20050831
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/current/
DIST_SUBDIR=	dvipdfmx

MAINTAINER=	matusita@FreeBSD.org
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/${TEXMFDIR}
PLIST_SUB=	DVIPDFMDIR=${DVIPDFMDIR} \
		FONTMAPDIR=${FONTMAPDIR} \
		FONTCMAPDIR=${FONTCMAPDIR} \
		MKTEXLSR=${MKTEXLSR} \
		ADOBECMAPDIR=${ADOBECMAPDIR}

TEXMFDIR=	share/texmf
DVIPDFMDIR=	${TEXMFDIR}/dvipdfm
FONTMAPDIR=	${TEXMFDIR}/fonts/map/dvipdfm
FONTCMAPDIR=	${TEXMFDIR}/fonts/cmap/dvipdfm
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

pre-install:
	${RM} -f ${WRKSRC}/data/config/dvipdfmx.cfg.orig \
		${WRKSRC}/data/config/cid-x.map

post-install:
	${MV} ${PREFIX}/${TEXMFDIR}/dvipdfm/config/glyphlist.txt \
		${LOCALBASE}/${FONTMAPDIR}/glyphlist.txt
	${MKDIR} ${LOCALBASE}/${FONTCMAPDIR}
	${INSTALL_DATA} ${FILESDIR}/cid-x.map.in \
		${LOCALBASE}/${FONTMAPDIR}/cid-x.map
	${LN} -s -f ${ADOBECMAPDIR} \
		${LOCALBASE}/${FONTCMAPDIR}/adobe-cmaps
	${LN} -s -f ${PREFIX}/${DVIPDFMDIR}/CMap \
		${LOCALBASE}/${FONTCMAPDIR}/
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
