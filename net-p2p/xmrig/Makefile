# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmrig
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	High performance Monero (XMR) CPU miner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd \
		libuv.so:devel/libuv

USES=		cmake:outsource
USE_GITHUB=	yes

PLIST_FILES=	bin/xmrig %%DATADIR%%/config.json

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src//config.json ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
