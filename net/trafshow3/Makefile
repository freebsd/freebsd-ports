# New ports collection makefile for:	trafshow
# Version required:     2.0
# Date created:         25 September 1996
# Whom:                 igor@zynaps.ru
#
# $Id: Makefile,v 1.7 1997/08/10 22:31:31 fenner Exp $
#

DISTNAME=	trafshow-2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/tcpip/netmaint/
EXTRACT_SUFX=	.tgz

MAINTAINER=     igor@zynaps.ru

MAN1=		trafshow.1

EXTRA_PATCH=    patch-ae

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
post-patch:
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/${EXTRA_PATCH}
.endif

.include <bsd.port.mk>
