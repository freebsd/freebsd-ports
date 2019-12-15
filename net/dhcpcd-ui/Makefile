# $FreeBSD$

PORTNAME=	dhcpcd-ui
PORTVERSION=	0.7.7
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/downloads/dhcpcd/ \
		https://cflags.cc/roy/dhcpcd/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK+ / Curses interface to dhcpcd

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		pkgconfig tar:xz

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-notification \
		--mandir=${MANPREFIX}/man \
		--with-dhcpcd-online \
		--with-icons

OPTIONS_DEFINE=		GTK3
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes

GTK3_USES=		gnome
GTK3_USE=		gnome=gdkpixbuf2,gtk30
GTK3_CONFIGURE_WITH=	gtk

.include <bsd.port.mk>
