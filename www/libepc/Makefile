# New ports collection makefile for:   libepc
# Date created:			24 Mar 2008
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libepc
PORTVERSION=	0.3.11
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		avahi-ui.0:${PORTSDIR}/net/avahi-gtk

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
