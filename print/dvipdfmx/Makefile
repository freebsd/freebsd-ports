# New ports collection makefile for:    dvipdfmx
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfmx
PORTVERSION=	20030313
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfmx/snapshot/

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Dvipdfm with Asian languages by CID-keyed font technology support

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PO
RTSDIR}/print/adobe-cmaps \
		kpsepath:${PORTSDIR}/print/teTeX

MAN1=		dvipdfm.1

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

pre-install:
	${CP} ${LOCALBASE}/bin/dvipdfm ${LOCALBASE}/bin/dvipdfm-orig || ${TRUE}
	${MV} ${LOCALBASE}/share/texmf/dvipdfm ${LOCALBASE}/share/texmf/dvipdfm-orig || ${TRUE}

post-install:
	@${LN} -fs ${LOCALBASE}/share/ghostscript/Resource ${PREFIX}/share/texmf/dvipdfm/

.include <bsd.port.mk>
