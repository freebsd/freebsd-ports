# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20040411
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/current/

MAINTAINER=	matusita@FreeBSD.org
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${LOCALBASE}/${TEXMFLOCAL}/ls-R:${PORTSDIR}/print/tex-texmflocal \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX-base

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/${TEXMFLOCAL}
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} \
		MKTEXLSR=${MKTEXLSR} \
		ADOBECMAPDIR=${ADOBECMAPDIR} \
		DVIPDFMCMAPDIR=${DVIPDFMCMAPDIR}

TEXMFLOCAL=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
DVIPDFMCMAPDIR=	${LOCALBASE}/${TEXMFLOCAL}/dvipdfm/CMap
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps

post-install:
	${LN} -s -f ${ADOBECMAPDIR} ${DVIPDFMCMAPDIR}/adobe-cmaps
	${MKTEXLSR}

.include <bsd.port.mk>
