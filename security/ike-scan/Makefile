# Ports collection makefile for:  ike-scan
# Date created:			  04 May 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ike-scan
PORTVERSION=	1.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/ike-scan/download/ \
		http://berlin.ccc.de/~cryx/ike-scan/

MAINTAINER=	onatan@gmail.com
COMMENT=	VPN scanner and identifier

GNU_CONFIGURE=	yes
xCONFIGURE_ARGS+=	--prefix=${PREFIX} --datadir=${PREFIX}/share --with-openssl
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share --with-openssl
MAN1=		ike-scan.1 psk-crack.1

post-install:
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.		for i in AUTHORS COPYING NEWS README TODO udp-backoff-fingerprinting-paper.txt
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.mk>
