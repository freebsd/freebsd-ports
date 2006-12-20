# New ports collection makefile for:	gnome-mount
# Date created:			04 June 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-mount/Makefile,v 1.4 2006/10/05 07:37:38 mezz Exp $
#

PORTNAME=	gnome-mount
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://people.freedesktop.org/~david/dist/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A front-end to mount, umount, and eject using HAL

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nautilus-extension
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-mount.schemas

post-extract:
	@${CP} -f ${FILESDIR}/mntent.h ${WRKSRC}/src

.include <bsd.port.mk>
