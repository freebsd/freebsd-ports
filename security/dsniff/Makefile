# New ports collection makefile for:	dsniff
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dsniff
PORTVERSION= 	1.7
CATEGORIES=	security
MASTER_SITES=	http://naughty.monkey.org/~dugsong/dsniff/

MAINTAINER=	kris@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet \
		${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libnet="${LOCALBASE}" --with-libnids="${LOCALBASE}"
USE_XLIB=	yes

MAN8=	arpredirect.8 dsniff.8 findgw.8 macof.8 mailsnarf.8 tcpkill.8 \
	tcpnice.8 urlsnarf.8 webspy.8

.include <bsd.port.mk>
