# New ports collection makefile for:	gtkglextmm
# Date created:				22 March 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglextmm
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkglext

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for GtkGLExt

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext \
		gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
