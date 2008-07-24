# New ports collection makefile for:   PolicyKit-gnome
# Date Created:			20 January 2008
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/policykit-gnome/Makefile,v 1.4 2008/02/15 16:48:08 mezz Exp $
#

PORTNAME=	policykit-gnome
PORTVERSION=	0.9
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-gnome-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicKit framework

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit \
    		sexy.2:${PORTSDIR}/x11-toolkits/libsexy

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget gnomevfs2 intlhack gnomedocutils gconf2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	polkit-gnome.schemas

.include <bsd.port.mk>
