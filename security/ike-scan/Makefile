# Ports collection makefile for:  ike-scan
# Date created:			  04 May 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	ike-scan
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	https://berlin.ccc.de/~cryx/

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
