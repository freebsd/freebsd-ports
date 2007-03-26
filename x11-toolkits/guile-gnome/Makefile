# New ports collection makefile for:	guile-gnome
# Date created:        			9th June 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guile-gnome
PORTVERSION=	0.20
PORTREVISION=	8
CATEGORIES=	x11-toolkits gnome scheme
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-guile/0.20
DISTNAME=	gnome-guile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Guile binding library for GNOME

LIB_DEPENDS=	guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix bonobo gtkhtml libglade
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-bonobo --with-gtkhtml --without-gal \
		--with-libglade --with-gdkpixbuf --with-ghttp
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-build:
	@${TOUCH} -f ${WRKSRC}/guile-gnome/gtkhtml/*.c

.include <bsd.port.mk>
