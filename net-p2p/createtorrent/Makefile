# New ports collection makefile for:	createtorrent
# Date created:				7 Jan 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	createtorrent
PORTVERSION=	1.1.2
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.createtorrent.com/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create BitTorrent files from the command line

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

PLIST_FILES=	bin/createtorrent

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
