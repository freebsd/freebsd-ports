# Created by yohanesu75@gmail.com
# $FreeBSD$

PORTNAME=	libwacom
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	wayland
MASTER_SITES=	https://sourceforge.net/projects/linuxwacom/files/libwacom/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

#LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:wayland/libgudev

USES=		gettext-runtime gmake libtool localbase pkgconfig \
		pathfix tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
