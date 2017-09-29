# Created by: barner
# $FreeBSD$

PORTNAME=	libfprint
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	lichray@gmail.com
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick \
		libnss3.so:security/nss

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:xz ssl
USE_LDCONFIG=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-DHAVE_MEMMEM
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
