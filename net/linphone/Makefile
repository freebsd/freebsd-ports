# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linphone
PORTVERSION=	0.12.0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm \
		speex.2:${PORTSDIR}/audio/speex \
		osip.9:${PORTSDIR}/net/libosip

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-platform-gnome-2 --disable-ipv6

MAN1=		linphone.1 linphonec.1 sipomatic.1

.include <bsd.port.mk>
