# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD$

PORTNAME=		nimbus
PORTVERSION=		0.1.7
PORTREVISION=		3
CATEGORIES=		x11-themes
MASTER_SITES=		http://dlc.sun.com/osol/jds/downloads/extras/nimbus/ \
			http://devio.us/~kpedersen/distfiles/

MAINTAINER=		kpedersen@opencde.org
COMMENT=		GTK+ 2.x engine from the OpenSolaris project

BROKEN=		unfetchable

BUILD_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/icon-naming-utils.pc:x11-themes/icon-naming-utils

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-static
INSTALLS_ICONS=		yes
INSTALL_TARGET=		install-strip
USES=			gettext gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=		yes
USE_GNOME=		gtk20 intltool

.include <bsd.port.mk>
