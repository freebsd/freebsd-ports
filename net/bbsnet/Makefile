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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A front-end of telnet client for multiple users or in private

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/bbsnet

post-patch:
	@${REINPLACE_CMD} -e 79d ${WRKSRC}/bbsnet.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbsnet ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for data in bbsdata Help Welcome
	@${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/etc/${PORTNAME}
.endfor

.include <bsd.port.mk>
