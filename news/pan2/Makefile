# New ports collection makefile for:	pan
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	pan
PORTVERSION=	0.8.0
CATEGORIES=	news gnome
MASTER_SITES=	ftp://source.rebelbase.com/pub/pan/${PORTVERSION}/

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		uu.1:${PORTSDIR}/converters/uulib
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -luu"

.include <bsd.port.mk>
