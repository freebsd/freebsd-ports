# New ports collection makefile for:	libfprint
# Date created:				April 12 2008
# Whom:					barner
#
# $FreeBSD$
#

PORTNAME=	libfprint
PORTVERSION=	0.4.0
CATEGORIES=	security
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	lichray@gmail.com
COMMENT=	Library for fingerprint reader devices

LIB_DEPENDS+=	Magick:${PORTSDIR}/graphics/ImageMagick \
		nss3:${PORTSDIR}/security/nss

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomehack glib20 pkgconfig

CFLAGS+=	-DHAVE_MEMMEM
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		libusb-1.0 is not avaible on FreeBSD < 8
.else
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
.endif

.include <bsd.port.post.mk>
