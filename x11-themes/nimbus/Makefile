# New ports collection makefile for:	nimbus
# Date created:		2011-04-07
# Whom:			Karsten Pedersen <kpedersen@opencde.org>
#
# $FreeBSD$
#

PORTNAME=		nimbus
PORTVERSION=		0.1.7
CATEGORIES=		x11-themes
MASTER_SITES=		http://dlc.sun.com/osol/jds/downloads/extras/nimbus/ \
			http://devio.us/~kpedersen/distfiles/

MAINTAINER=		kpedersen@opencde.org
COMMENT=		GTK+ 2.x engine from the OpenSolaris project

BUILD_DEPENDS=		${LOCALBASE}/bin/intltoolize:${PORTSDIR}/textproc/intltool \
			${LOCALBASE}/libdata/pkgconfig/icon-naming-utils.pc:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=		${LOCALBASE}/bin/gtk-demo:${PORTSDIR}/x11-toolkits/gtk20

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_ICONS=		yes
USE_LDCONFIG=		yes
USE_GNOME=		gtk20

.include <bsd.port.mk>
