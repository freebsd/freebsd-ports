# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnumeric
PORTVERSION=	0.54
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnumeric

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		glade.3:${PORTSDIR}/devel/libglade \
		guile.6:${PORTSDIR}/lang/guile

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libole2/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} --with-guile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
