# New ports collection makefile for:	gtk-vnc
# Date created:				16 December 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-vnc
PORTVERSION=	0.3.4
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-vnc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls

USE_XLIB=	yes
USE_GNOME=	pygtk2 gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
