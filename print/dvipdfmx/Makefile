# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20031116
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/release/:main \
		http://project.ktug.or.kr/dvipdfmx/snapshot/patch/:patch1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main \
		dvipdfmx-${PORTVERSION}.patch:patch1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX

GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1

post-patch:
	(cd ${WRKSRC}/src; ${PATCH} --quiet < ${DISTDIR}/dvipdfmx-${PORTVERSION}.patch)

post-install:
	@${LN} -fs ${LOCALBASE}/share/ghostscript/Resource ${PREFIX}/share/texmf/dvipdfm/
	${LOCALBASE}/bin/mktexlsr

.include <bsd.port.mk>
