# Ports collection makefile for:  thcrut
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thcrut
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://www.thehackerschoice.com/releases/

MAINTAINER=	kris@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-libnet=${LOCALBASE} \
		 --sysconfdir=${PREFIX}/share/thcrut

.include <bsd.port.mk>
