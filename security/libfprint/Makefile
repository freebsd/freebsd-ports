# New ports collection makefile for:	libfprint
# Date created:				April 12 2008
# Whom:					barner
#
# $FreeBSD$
#

PORTNAME=	libfprint
PORTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fprint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS+=	Magick:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GNOME=	glib20 pkgconfig

CONFIGURE_ENV+=	CRYPTO_CFLAGS=-I${OPENSSLINC} \
		CRYPTO_LIBS=-lcrypto \
		CFLAGS="${CFLAGS} -DHAVE_MEMMEM"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb
.endif

.include <bsd.port.post.mk>
