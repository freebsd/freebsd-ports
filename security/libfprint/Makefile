# New ports collection makefile for:	libfprint
# Date created:				April 12 2008
# Whom:					barner
#
# $FreeBSD$
#

PORTNAME=	libfprint
PORTVERSION=	0.0.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fprint

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS+=	Magick:${PORTSDIR}/graphics/ImageMagick \
		usb:${PORTSDIR}/devel/libusb

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GNOME=	glib20 pkgconfig

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CRYPTO_CFLAGS=-I${OPENSSLINC} \
		CRYPTO_LIBS=-lcrypto \
		CFLAGS="${CFLAGS} -DHAVE_MEMMEM"

.include <bsd.port.post.mk>
