# New ports collection makefile for:   PolicyKit-gnome
# Date Created:			20 January 2008
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/policykit-gnome/Makefile,v 1.6 2008/10/03 17:19:43 marcus Exp $
#

PORTNAME=	policykit-gnome
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-gnome-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicKit framework

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget intlhack gnomedocutils gconf2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	polkit-gnome.schemas

.include <bsd.port.mk>
