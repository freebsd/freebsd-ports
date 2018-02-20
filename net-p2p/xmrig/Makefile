# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmrig
PORTVERSION=	2.4.5
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

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS}
USERS=		xmrig

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/config.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
