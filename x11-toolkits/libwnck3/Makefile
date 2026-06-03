PORTNAME=	libwnck
PORTVERSION=	43.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists
WWW=		https://gitlab.gnome.org/GNOME/libwnck

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gettext-tools gnome localbase meson pkgconfig tar:xz \
		xorg
USE_GNOME=	cairo gdkpixbuf gtk30 introspection:build
USE_XORG=	x11 xi xrender xres
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgtk_doc=false \
		-Dinstall_tools=false

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_MESON_ENABLED=	startup_notification

.include <bsd.port.mk>
