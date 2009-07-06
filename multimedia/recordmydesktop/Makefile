# New ports collection makefile for:	recordmydesktop
# Date created:				18 July 2007
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	recordmydesktop
DISTVERSION=	0.3.8.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Record desktop sessions to an Ogg-Theora-Vorbis file

LIB_DEPENDS=	theora.0:${PORTSDIR}/multimedia/libtheora \
		jack.0:${PORTSDIR}/audio/jack

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-oss=yes \
			--enable-jack=yes

MAN1=	recordmydesktop.1

USE_XORG=	ice sm x11 xext xfixes xdamage
PLIST_FILES=	bin/recordmydesktop

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
