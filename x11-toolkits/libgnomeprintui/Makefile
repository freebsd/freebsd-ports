# Created by: Maxim Sobolev <sobomax@FreBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeprintui/Makefile,v 1.75 2010/09/28 16:07:36 kwm Exp $

PORTNAME=	libgnomeprintui
PORTVERSION=	2.18.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_XORG=	x11 xpm
USES=		bison pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix libgnomeprint libgnomecanvas \
		intlhack ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
