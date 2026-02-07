PORTNAME=	libcroco
PORTVERSION=	0.6.13
PORTREVISION=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	CSS2 parsing library
WWW=		http://www.freespiders.org/projects/libcroco/

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USES=		cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
CONFIGURE_ARGS=	--disable-gtk-doc-html
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

PLIST_SUB=	VERSION="0.6"

.include <bsd.port.mk>
