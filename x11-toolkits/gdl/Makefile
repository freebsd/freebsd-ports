PORTNAME=	gdl
PORTVERSION=	3.40.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools
WWW=		https://www.gnome.org/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USE_GNOME=	cairo gdkpixbuf gtk30 intltool introspection:build libxml2
USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
