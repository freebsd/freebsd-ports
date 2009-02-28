# New ports collection makefile for:	libnice
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnice
PORTVERSION=	0.0.4
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

WRKSRC=		${WRKDIR}/nice-${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack gnometarget
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|__BYTE_ORDER|_BYTE_ORDER|g ; \
	    	s|__BIG_ENDIAN|_BIG_ENDIAN|g' \
		${WRKSRC}/stun/md5.c \
		${WRKSRC}/stun/sha1.c

.include <bsd.port.mk>
