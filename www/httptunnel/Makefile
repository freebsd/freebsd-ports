# New ports collection makefile for:    httptunnel
# Date created:         March 20 2000
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httptunnel
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.Awfulhak.org/httptunnel/ \
		ftp://ftp.nocrew.org/pub/nocrew/unix/ \
		http://www.nocrew.org/software/httptunnel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tunnel a TCP/IP connection through a HTTP/TCP/IP connection

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
.if defined(ENABLE_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
MAN1=		hts.1 htc.1

USE_RC_SUBR=	hts htc

PLIST_FILES=	bin/hts bin/htc

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
