# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtksourceview/Makefile,v 1.46 2007/05/19 21:36:33 marcus Exp $

PORTNAME=	gtksourceview
PORTVERSION=	1.8.5
PORTREVISION?=	8
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A text widget that adds syntax highlighting to the GtkTextView widget

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USES=		gettext gmake pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gnomehack libgnome libgnomeprintui intlhack \
		ltverhack referencehack
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lgnuregex"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.mk>

.endif
