# New ports collection makefile for:	gtksourceview
# Date created:				07 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtksourceview/Makefile,v 1.23 2005/10/03 15:24:49 ahze Exp $
#

PORTNAME=	gtksourceview
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A text widget that adds syntax highlighting to the GtkTextView widget

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:15
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomeprefix gnomehack libgnome libgnomeprintui intlhack \
		ltverhack
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.mk>
