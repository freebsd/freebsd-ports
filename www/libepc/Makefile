# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libepc/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libepc
PORTVERSION=	0.4.4
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libavahi-ui-gtk3.so:${PORTSDIR}/net/avahi-gtk3

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
