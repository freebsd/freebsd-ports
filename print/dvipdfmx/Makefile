# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20030313
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/dvipdfmx/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-base-0.1.tar.gz

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

pre-install:
	${CP} ${LOCALBASE}/bin/dvipdfm ${LOCALBASE}/bin/dvipdfm-orig > /dev/null 2>&1 || ${TRUE}
	${MV} ${LOCALBASE}/share/texmf/dvipdfm ${LOCALBASE}/share/texmf/dvipdfm-orig > /dev/null 2>&1 || ${TRUE}

post-install:
	@${LN} -fs ${LOCALBASE}/share/ghostscript/Resource ${PREFIX}/share/texmf/dvipdfm/
	${MKDIR} ${LOCALBASE}/share/texmf/dvipdfm/base
	${CP} ${WRKDIR}/base/* ${LOCALBASE}/share/texmf/dvipdfm/base
	${RM} ${LOCALBASE}/share/texmf/dvipdfm/config/dvipdfmx.cfg.orig
	${LOCALBASE}/bin/mktexlsr

.include <bsd.port.mk>
