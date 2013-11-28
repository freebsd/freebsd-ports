# Created by: Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
# $FreeBSD$

PORTNAME=	libgksu
PORTVERSION=	2.0.12
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library providing su and sudo functionality

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libglade-2.0.so:${PORTSDIR}/devel/libglade2 \
		libgcr.so:${PORTSDIR}/security/gnome-keyring \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xauth:${PORTSDIR}/x11/xauth \
		sudo:${PORTSDIR}/security/sudo

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gconf2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	gksu.schemas

.include <bsd.port.mk>
