# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbredir
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://spice-space.org/download/usbredir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	protocol for redirection of USB traffic

USES=		gmake libtool pathfix pkgconfig tar:bzip2
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ENV=	LIBUSB_CFLAGS=-DLIBUSB_CALL= LIBUSB_LIBS=-lusb

.include <bsd.port.mk>
