# New ports collection makefile for:   polkit-gnome
# Date Created:			30 Juli 2009
# Whom:				Koop Mast<kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/polkit-gnome/Makefile,v 1.10 2010/05/10 04:21:19 marcus Exp $
#

PORTNAME=	polkit-gnome
PORTVERSION=	0.96
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicKit framework

LIB_DEPENDS=	polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
