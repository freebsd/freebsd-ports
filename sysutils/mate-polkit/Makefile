PORTNAME=	mate-polkit
DISTVERSION=	1.28.1
PORTREVISION=	2
CATEGORIES=	sysutils mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE frontend to the PolicyKit framework
WWW=		https://mate-desktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libaccountsservice.so:sysutils/accountsservice

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GNOME=	cairo gdkpixbuf gtk30 intltool introspection:build
USE_LDCONFIG=	yes
PORTSCOUT=	site:https://github.com/mate-desktop/mate-polkit/releases/ limitw:1,even
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
