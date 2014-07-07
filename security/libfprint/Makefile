# Created by: barner
# $FreeBSD$

PORTNAME=	libfprint
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	lichray@gmail.com
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS=	libMagickCore-6.Q*.so:${PORTSDIR}/graphics/ImageMagick \
		libnss3.so:${PORTSDIR}/security/nss

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GNOME=	glib20

CONFIGURE_ENV=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
CPPFLAGS+=	-DHAVE_MEMMEM
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
