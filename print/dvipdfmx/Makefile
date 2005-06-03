# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20050201
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/
DIST_SUBDIR=	dvipdfmx

PATCH_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/patch/
PATCHFILES=	mpost-c-20050201.diff tfm-c-20050201.diff

MAINTAINER=	matusita@FreeBSD.org
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${LOCALBASE}/${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/${TEXMFLOCALDIR}
PLIST_SUB=	DVIPDFMDIR=${DVIPDFMDIR} \
		FONTMAPDIR=${FONTMAPDIR} \
		FONTCMAPDIR=${FONTCMAPDIR} \
		MKTEXLSR=${MKTEXLSR} \
		ADOBECMAPDIR=${ADOBECMAPDIR}

TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${TEXMFLOCALDIR}/ls-R
DVIPDFMDIR=	${TEXMFLOCALDIR}/dvipdfm
FONTMAPDIR=	${TEXMFLOCALDIR}/fonts/map/dvipdfm
FONTCMAPDIR=	${TEXMFLOCALDIR}/fonts/cmap/dvipdfm
ADOBECMAPDIR=	${LOCALBASE}/share/ghostscript/Resource
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

post-install:
	${MKDIR} ${LOCALBASE}/${FONTCMAPDIR}
	${MV} ${LOCALBASE}/${DVIPDFMDIR}/config/cid-x.map \
		${LOCALBASE}/${FONTMAPDIR}/cid-x.map
	${MV} ${LOCALBASE}/${DVIPDFMDIR}/CMap/glyphlist.txt \
		${LOCALBASE}/${DVIPDFMDIR}/config/glyphlist.txt
	${MV} ${LOCALBASE}/${DVIPDFMDIR}/CMap \
		${LOCALBASE}/${FONTCMAPDIR}/CMap
	${LN} -s -f ${ADOBECMAPDIR} \
		${LOCALBASE}/${FONTCMAPDIR}/adobe-cmaps
	${MKTEXLSR}

.include <bsd.port.mk>
