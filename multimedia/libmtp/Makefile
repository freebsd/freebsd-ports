# Created by: Petar Zhivkov Petrov <pesho.petrov@gmail.com>
# $FreeBSD$

PORTNAME=	libmtp
PORTVERSION=	1.1.11
CATEGORIES=	multimedia audio
MASTER_SITES=	SF

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21+

CONFLICTS_INSTALL=libosmo-sccp-[0-9]* # lib/libmtp.a

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=	MTPZ
MTPZ_DESC=	Enable functionality to connect to MTPZ devices

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
INSTALL_TARGET=	install-strip
USES=		iconv libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes

.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
.endif

MTPZ_CONFIGURE_ENABLE=	mtpz
MTPZ_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

post-patch:
.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
	@${REINPLACE_CMD} -i .pkgconf.bak -e \
		'/LIBUSB_REQUIRES/s|libusb-1.0||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -i .pkgconf.bak -e \
		'/Libs.private/s|:|& @LIBUSB_LIBS@|' ${WRKSRC}/libmtp.pc.in
.endif

.include <bsd.port.mk>
