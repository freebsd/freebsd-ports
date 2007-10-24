# New ports collection makefile for:	gnome-mount
# Date created:			04 June 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-mount/Makefile,v 1.16 2007/05/19 21:36:22 marcus Exp $
#

PORTNAME=	gnome-mount
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://people.freedesktop.org/~david/dist/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A front-end to mount, umount, and eject using HAL

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.1:${PORTSDIR}/devel/libnotify

USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nautilus-extension
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-mount.schemas
MAN1=		gnome-mount.1

post-patch:
	@${REINPLACE_CMD} -e 's|0.5.8.1|0.5.8|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
