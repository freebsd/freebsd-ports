# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/libwnck3/Makefile 18903 2013-11-18 20:04:17Z kwm $

PORTNAME=	libwnck
PORTVERSION=	3.4.5
PORTREVISION?=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification

USE_XORG=	xres x11
USE_GNOME=	gtk30 intlhack introspection:build ltverhack referencehack
USES=		bison gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tools
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwnck-3.so.0

.include <bsd.port.mk>

.endif
