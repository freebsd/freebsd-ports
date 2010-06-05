# New ports collection makefile for:	GtkGLExt
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL extension to GTK

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
USE_GL=		yes
USE_XORG=	xt
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DGDK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/examples/Makefile.in ${WRKSRC}/gtk/Makefile.in 

.include <bsd.port.mk>
