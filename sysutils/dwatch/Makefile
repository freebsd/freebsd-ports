# New ports collection makefile for:	dwatch
# Date created:		14 Aug 2002
# Whom:			Andrew Turner <zombie@i4free.co.nz>
#
# $FreeBSD$
#

PORTNAME=	dwatch
PORTVERSION=	0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://siag.nu/pub/dwatch/ \
		http://siag.nu/pub/dwatch/

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Dwatch - A Daemon Watcher

MAN1=		dwatch.1

pre-install:
	${INSTALL_DATA} ${WRKSRC}/dwatch.conf ${PREFIX}/etc/dwatch.conf-dist

post-install:
	${STRIP_CMD} ${PREFIX}/bin/dwatch

.include <bsd.port.mk>
