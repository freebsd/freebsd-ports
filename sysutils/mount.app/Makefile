# New ports collection makefile for:    mount.app
# Date created:         		20 Mar 2003
# Whom:                 		Gaspar Chilingarov <nm@web.am>
#
# $FreeBSD$
#

PORTNAME=	mountapp
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mountapp

MAINTAINER=	nm@web.am
COMMENT=	Windowmaker application, Resembles wmmount with extra functionality

BUILD_DEPENDS+=	${X11BASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker

USE_GETTEXT=	yes
USE_GNOME=	gtk12 glib12

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
