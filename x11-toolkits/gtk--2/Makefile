# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtkmm
PORTVERSION=	2.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmm

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--enable-static=yes \
		--without-gnome \
		--with-sigc-prefix=${LOCALBASE}

.include <bsd.port.mk>
