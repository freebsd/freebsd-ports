# New ports collection makefile for:	trafshow
# Version required:     2.0
# Date created:         25 September 1996
# Whom:                 igor@zynaps.ru
#
# $Id$
#

DISTNAME=	trafshow-2.0
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.kiae.su/unix/tcpip/netmaint/
EXTRACT_SUFX=	.tgz

MAINTAINER=     igor@zynaps.ru

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/trafshow.1
.endif

.include <bsd.port.mk>
