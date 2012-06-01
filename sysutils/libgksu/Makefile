# New ports collection makefile for:   libgksu1.2
# Date created:        1 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	libgksu
PORTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Library providing su and sudo functionality

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		glade-2.0:${PORTSDIR}/devel/libglade2 \
		gcr.0:${PORTSDIR}/security/gnome-keyring \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xauth:${PORTSDIR}/x11/xauth \
		sudo:${PORTSDIR}/security/sudo

USE_GNOME=	pkgconfig glib20 gconf2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	gksu.schemas
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
