# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcroco
PORTVERSION=	0.6.11
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CSS2 parsing library

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
CONFIGURE_ARGS=	--disable-gtk-doc-html
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="0.6"

.include <bsd.port.mk>
