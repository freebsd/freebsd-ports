# Ports collection makefile for:  ike-scan
# Date created:			  04 May 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	ike-scan
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/ike-scan/download/ \
		http://berlin.ccc.de/~cryx/ike-scan/

MAINTAINER=	Yonatan@xpert.com
COMMENT=	VPN scanner and identifier

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	"--datadir=${DATADIR}"

post-install:
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.		for i in AUTHORS COPYING NEWS README TODO udp-backoff-fingerprinting-paper.txt
			${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.mk>
