# New ports collection makefile for:	GtkGLExt
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL extension to GTK

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_GL=		yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
