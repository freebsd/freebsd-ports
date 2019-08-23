# Created by: Nick Wolff <darkfiberiru@gmail.com>
# $FreeBSD$

PKGNAMESUFFIX=	-www

COMMENT=	Remmina plugin to open an authenticated web-browser

USES=		compiler:c11 gnome
USE_GNOME=	cairo
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
				libsoup-2.4.so:devel/libsoup

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
