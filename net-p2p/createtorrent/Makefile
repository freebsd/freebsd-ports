# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	createtorrent
PORTVERSION=	1.1.4
CATEGORIES=	net-p2p
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create BitTorrent files from the command line

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

PLIST_FILES=	bin/createtorrent

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
