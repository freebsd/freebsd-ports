# New ports collection makefile for:   bbsnet
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	bbsnet
PORTVERSION=	2.8
CATEGORIES=	net
MASTER_SITES=	http://linux.ee.tku.edu.tw/~kids/resource/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/bbsnet/

MAINTAINER=	statue@freebsd.sinica.edu.tw

WRKSRC=		${WRKDIR}/bbsnet

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbsnet ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for data in bbsdata Help Welcome
	@${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/etc/${PORTNAME}
.endfor

.include <bsd.port.mk>
