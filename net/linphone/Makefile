# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linphone
PORTVERSION=	0.11.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/${PORTVERSION}/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	osip.9:${PORTSDIR}/net/libosip \
		ogg.4:${PORTSDIR}/audio/libogg

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure oRTP/configure speex/configure osipua/configure
USE_GNOME=	gnomehack gnomeprefix libgnomeui gnomepanel
CONFIGURE_ARGS=	--disable-ipv6
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		linphone.1 linphonec.1 sipomatic.1

.include <bsd.port.mk>
