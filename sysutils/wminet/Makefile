# New ports collection makefile for:   wminet
# Date created:        23 May 1999
# Whom:                Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=	wminet
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dockable inetd monitor

WRKSRC=		${WRKDIR}/wminet.app/wminet

USE_XORG=	x11 xpm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../HINTS ${DOCSDIR}
.endif

.include <bsd.port.mk>
