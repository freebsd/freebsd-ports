# New ports collection makefile for:    mount.app
# Date created:         		20 Mar 2003
# Whom:                 		Gaspar Chilingarov <nm@web.am>
#
# $FreeBSD$
#

PORTNAME=	mountapp
PORTVERSION=	3.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=   http://mountapp.sourceforge.net/

MAINTAINER=	nm@web.am
COMMENT=	Windowmaker application, Resembles wmmount with extra functionality

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		gmodule12:${PORTSDIR}/devel/glib12
BUILD_DEPENDS+=	${X11BASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker

USE_GNOME=	gtk12 glib12

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
