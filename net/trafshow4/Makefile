# New ports collection makefile for:	trafshow
# Version required:     2.0
# Date created:         17 January 1996
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $Id: Makefile,v 1.2 1996/05/04 01:57:18 asami Exp $
#

DISTNAME=	trafshow-2.0
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.kiae.su/unix/tcpip/netmaint/
EXTRACT_SUFX=	.tgz

MAINTAINER=	igor@zynaps.ru

post-install:
	strip ${PREFIX}/bin/trafshow
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/trafshow.1
.endif

.include <bsd.port.mk>
