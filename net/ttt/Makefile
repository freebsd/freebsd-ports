# New ports collection makefile for:    ttt
# Date created:         22 September 1998
# Whom:                 Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ttt
PORTVERSION=	1.8.2
CATEGORIES=	net tk84 ipv6
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	kjc@csl.sony.co.jp
COMMENT=	Tele Traffic Tapper, a network traffic monitoring tool

LIB_DEPENDS=	BLT24.3:${PORTSDIR}/x11-toolkits/blt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4
INSTALL_TARGET=	install install-man
MAN1=		ttt.1 tttprobe.1 tttview.1

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
