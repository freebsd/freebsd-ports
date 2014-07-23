# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepc
PORTVERSION=	0.3.11
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libavahi-ui.so:${PORTSDIR}/net/avahi-gtk

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
