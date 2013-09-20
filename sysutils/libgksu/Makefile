# Created by: Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
# $FreeBSD$

PORTNAME=	libgksu
PORTVERSION=	2.0.12
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Library providing su and sudo functionality

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		glade-2.0:${PORTSDIR}/devel/libglade2 \
		gcr:${PORTSDIR}/security/gnome-keyring \
		startup-notification-1:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xauth:${PORTSDIR}/x11/xauth \
		sudo:${PORTSDIR}/security/sudo

USES=		desktop-file-utils pkgconfig
USE_GNOME=	glib20 gconf2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	gksu.schemas
USE_GMAKE=	yes
MAN1=		gksu-properties.1

NO_STAGE=	yes
.include <bsd.port.mk>
