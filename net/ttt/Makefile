# New ports collection makefile for:    ttt
# Date created:         22 September 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	1.6
CATEGORIES=	net tk83 ipv6
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	kjc@csl.sony.co.jp

# the tcl/tk LIB_DEPENDS has to match that of ports/x11-toolkits/blt.
LIB_DEPENDS=	BLT24.2:${PORTSDIR}/x11-toolkits/blt \
		tcl83.1:${PORTSDIR}/lang/tcl83 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install-man
MAN1=		ttt.1 tttprobe.1 tttview.1

.include <bsd.port.mk>
