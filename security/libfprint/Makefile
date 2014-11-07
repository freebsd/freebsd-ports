# Created by: barner
# $FreeBSD$

PORTNAME=	libfprint
PORTVERSION=	0.5.1
CATEGORIES=	security
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	lichray@gmail.com
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS=	libMagickCore-6.Q16.so:${PORTSDIR}/graphics/ImageMagick \
		libnss3.so:${PORTSDIR}/security/nss

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
CPPFLAGS+=	-DHAVE_MEMMEM
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
