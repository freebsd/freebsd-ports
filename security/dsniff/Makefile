# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsniff
DISTVERSION=	2.4b1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/beta/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libnet.so:net/libnet
BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet=${LOCALBASE}
DESTDIRNAME=	install_prefix
USES=		gettext pkgconfig ssl
USE_GNOME=	glib20
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/(.*)..$/\1/}

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_USE=	xorg=x11,xmu
X11_CONFIGURE_WITH=x

post-patch:
	@${REINPLACE_CMD} -e 's,csin,_csin,g' \
		${WRKSRC}/webmitm.c \
		${WRKSRC}/sshmitm.c

.include <bsd.port.mk>
