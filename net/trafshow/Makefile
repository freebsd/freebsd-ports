# New ports collection makefile for:	trafshow
# Version required:     2.0
# Date created:         17 January 1996
# Whom:                 igor@pkaub.ru
#
# $Id$
#

DISTNAME=	trafshow-2.0
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.kiae.su/unix/tcpip/netmaint/
EXTRACT_SUFX=	.tgz

MAINTAINER=     igor@pkaub.ru

post-install:
	strip ${PREFIX}/bin/trafshow
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/trafshow.1
.endif

.include <bsd.port.mk>
