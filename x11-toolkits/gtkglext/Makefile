# New ports collection makefile for:	GtkGLExt
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	0.7.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fuyuki@hadaly.org

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
#CONFIGURE_ARGS=	--enable-mesa-ext
USE_GMAKE=	yes

.include <bsd.port.mk>
