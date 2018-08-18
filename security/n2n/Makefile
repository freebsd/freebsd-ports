# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	n2n
PORTVERSION=	2.4
CATEGORIES=	security net

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Layer Two Peer-to-peer VPN

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	ntop

PLIST_FILES=	sbin/edge \
		sbin/supernode \
		man/man1/supernode.1.gz \
		man/man7/n2n.7.gz \
		man/man8/edge.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edge ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/supernode ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/edge.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/supernode.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/n2n.7 ${STAGEDIR}${MANPREFIX}/man/man7

.include <bsd.port.mk>
