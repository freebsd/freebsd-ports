# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatewnck
PORTVERSION=	1.6.1
CATEGORIES=	x11-toolkits mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_XORG=	x11 xres
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 intlhack \
		introspection:build ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmatewnck.so.0

.include <bsd.port.mk>
