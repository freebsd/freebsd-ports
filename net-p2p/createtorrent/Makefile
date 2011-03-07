# New ports collection makefile for:	createtorrent
# Date created:				7 Jan 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	createtorrent
PORTVERSION=	1.1.4
CATEGORIES=	net-p2p
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create BitTorrent files from the command line

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2

PLIST_FILES=	bin/createtorrent

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
