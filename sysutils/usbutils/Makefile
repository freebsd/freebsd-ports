# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbutils
PORTVERSION=	0.86
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-usb/${PORTNAME}

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Utility for listing USB devices

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR} --enable-zlib
USES=		gmake pkgconfig

MAN1=		usb-devices.1
MAN8=		lsusb.8
PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-L/usr/lib -lusb"

post-patch:
	@${REINPLACE_CMD} -i '' \
		-e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/usb-devices

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

.include <bsd.port.mk>
