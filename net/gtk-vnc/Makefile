# New ports collection makefile for:	gtk-vnc
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-vnc
PORTVERSION=	0.3.9
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GNOME=	pygtk2 gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtkglext=yes

.include <bsd.port.mk>
