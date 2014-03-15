# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbredir
PORTVERSION=	0.6
CATEGORIES=	net devel
MASTER_SITES=	http://spice-space.org/download/usbredir/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	protocol for redirection of USB traffic

USES=		gmake pkgconfig tar:bzip2
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
CONFIGURE_ENV+=	LIBUSB_CFLAGS=-I/usr/include\ -DLIBUSB_CALL=
CONFIGURE_ENV+=	LIBUSB_LIBS=-lusb

.include <bsd.port.options.mk>

MAKE_ENV+=	PKG_CONFIG_PATH=${FILESDIR}

post-patch:
	@${REINPLACE_CMD} "s|\\\$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|" ${WRKSRC}/*/Makefile.in ${WRKSRC}/*/Makefile.am

.include <bsd.port.mk>
