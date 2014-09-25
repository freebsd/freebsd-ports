# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/math/gcalctool/Makefile,v 1.140 2010/11/15 22:06:10 kwm Exp $

PORTNAME=	gcalctool
PORTVERSION=	5.32.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-2.31.*

USES=		bison gettext gmake libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack gconf2 gnomedocutils gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
