# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	libsynce
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
PKGNAMEPREFIX=	synce-

MAINTAINER=	webmaster@kibab.com
COMMENT=	Library to support communication with WinCE devices

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libhal.so:sysutils/hal

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pathfix iconv pkgconfig libtool
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG} \
			--enable-dccm-file-support=no \
			--enable-hal-support=yes \
			--enable-odccm-support=no

.include <bsd.port.mk>
