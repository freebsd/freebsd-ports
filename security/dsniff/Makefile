# New ports collection makefile for:	dsniff
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dsniff
PORTVERSION=	2.3
CATEGORIES=	security
MASTER_SITES=	http://naughty.monkey.org/~dugsong/dsniff/

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet \
		${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes

MAN8=	arpspoof.8 dsniff.8 macof.8 mailsnarf.8 tcpkill.8 \
	tcpnice.8 urlsnarf.8 filesnarf.8 dnsspoof.8 msgsnarf.8 \
	sshmitm.8 webmitm.8

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=	X11=''
MAN8+=	webspy.8
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.endif

.include <bsd.port.mk>
