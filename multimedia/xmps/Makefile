# New ports collection makefile for:	xmps
# Date created:			15 June 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.1.0
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www-eleves.enst-bretagne.fr/~chavarri/xmps/sources/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	smpeg.0:${PORTSDIR}/graphics/smpeg \
		gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
 		GLIB_CONFIG="${GLIB_CONFIG}" \
		SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
