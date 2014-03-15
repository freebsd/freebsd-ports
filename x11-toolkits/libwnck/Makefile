# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libwnck/Makefile,v 1.133 2010/11/17 11:38:29 kwm Exp $

PORTNAME=	libwnck
PORTVERSION=	2.30.6
PORTREVISION?=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

USE_XORG=	xres
USES+=		bison pathfix gettext gmake pkgconfig
USE_GNOME=	gtk20 ltverhack referencehack intlhack introspection:build,run
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	startup-notification-1:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.include <bsd.port.mk>

.endif
