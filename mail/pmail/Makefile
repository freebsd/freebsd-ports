# New ports collection makefile for:	pmail
# Date created:				27 July 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmail
PORTVERSION=	0.5.3
CATEGORIES=	mail python gnome
MASTER_SITES=	http://www.toad.net/~sbender/pmail/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome

USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
