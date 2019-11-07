# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwnck
PORTVERSION=	3.24.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USES+=		bison gettext gmake gnome libtool localbase pathfix pkgconfig \
		xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack introspection:build \
		referencehack
USE_XORG=	xext xrender xres x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tools
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification

.include <bsd.port.mk>

.endif
