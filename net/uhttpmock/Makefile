# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	uhttpmock
PORTVERSION=	0.5.0
CATEGORIES=	net gnome
MASTER_SITES=	http://tecnocode.co.uk/downloads/uhttpmock/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HTTP web service mocking library for GNOME

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		vapigen:${PORTSDIR}/lang/vala \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
