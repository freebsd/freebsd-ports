# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION= 	0.8.1
CATEGORIES=	mail gnome
MASTER_SITES=	ftp://ftp.newton.cx/pub/balsa/ \
		http://www.theochem.kth.se/~pawsa/balsa/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		PropList.2:${PORTSDIR}/devel/libPropList

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		GTK_CONFIG='${GTK_CONFIG}' \
		GLIB_CONFIG='${GLIB_CONFIG}' \
		LIBS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} \
		--enable-threads

MAN1=		balsa.1

.include <bsd.port.mk>
