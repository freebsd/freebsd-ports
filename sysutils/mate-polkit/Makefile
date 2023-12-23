PORTNAME=	mate-polkit
PORTVERSION=	1.26.0
PORTREVISION=	2
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE frontend to the PolicyKit framework
WWW=		https://mate-desktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libaccountsservice.so:sysutils/accountsservice

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
