# Ports collection makefile for: usbredir
# Date created: Mon Aug 15 18:16:38 CEST 2011
# Whom:         Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	usbredir
PORTVERSION=	0.6
CATEGORIES=	net devel
MASTER_SITES=	http://spice-space.org/download/usbredir/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	protocol for redirection of USB traffic

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
CONFIGURE_ENV+=	LIBUSB_CFLAGS=-I/usr/include\ -DLIBUSB_CALL=
CONFIGURE_ENV+=	LIBUSB_LIBS=-lusb
MAN1=		usbredirserver.1

.include <bsd.port.options.mk>

.if ${OSVERSION} < 803000
IGNORE=		needs libusb_get_device_speed()
.else
MAKE_ENV+=	PKG_CONFIG_PATH=${FILESDIR}
.endif

post-patch:
	@${REINPLACE_CMD} "s|\\\$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|" ${WRKSRC}/*/Makefile.in ${WRKSRC}/*/Makefile.am

.include <bsd.port.mk>
