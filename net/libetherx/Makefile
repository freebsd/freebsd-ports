# New ports collection makefile for:	libetherx
# Date created:			4 April 2000
# Whom:				Kostya Lukin <lukin@okbmei.msk.su>
#
# $FreeBSD$
#

PORTNAME=	libetherx
PORTVERSION=	0.9
CATEGORIES=     net
MASTER_SITES=	http://download.jabber.org/dists/0.9/final/

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	jabber.0:${PORTSDIR}/net/libjabber \
		pth.13:${PORTSDIR}/devel/pth \
		adns.0:${PORTSDIR}/net/adns

USE_LIBTOOL=	yes

MAN1=		etherx-config.1

.include <bsd.port.mk>
