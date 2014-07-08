# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	ike-scan
PORTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	http://www.nta-monitor.com/tools/ike-scan/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VPN scanner and identifier

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share --with-openssl=${LOCALBASE}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING NEWS README TODO \
		udp-backoff-fingerprinting-paper.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
