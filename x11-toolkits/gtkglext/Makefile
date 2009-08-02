# New ports collection makefile for:	GtkGLExt
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL extension to GTK

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
USE_GL=		yes
USE_XORG=	xt
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.mk>
