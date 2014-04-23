# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtksourceview/Makefile,v 1.46 2007/05/19 21:36:33 marcus Exp $

PORTNAME=	gtksourceview
PORTVERSION=	1.8.5
PORTREVISION?=	10
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Widget that adds syntax highlighting to GtkTextView

USES+=		tar:bzip2

.if !defined(REFERENCE_PORT)

USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix libgnome libgnomeprintui intlhack referencehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lgnuregex"
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

.endif
