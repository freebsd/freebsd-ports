# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httptunnel
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.Awfulhak.org/httptunnel/ \
		ftp://ftp.nocrew.org/pub/nocrew/unix/ \
		http://www.nocrew.org/software/httptunnel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tunnel a TCP/IP connection through a HTTP/TCP/IP connection

OPTIONS_DEFINE=	DEBUG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
DEBUG_CONFIGURE_ENABLE=	debug

USE_RC_SUBR=	hts htc
USERS=		httptunnel
GROUPS=		httptunnel

PLIST_FILES=	bin/hts bin/htc \
		man/man1/hts.1.gz man/man1/htc.1.gz

.include <bsd.port.mk>
