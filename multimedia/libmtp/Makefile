# Created by: Petar Zhivkov Petrov <pesho.petrov@gmail.com>
# $FreeBSD$

PORTNAME=	libmtp
PORTVERSION=	1.1.8
CATEGORIES=	multimedia audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21 # or any later version

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=	MTPZ
MTPZ_DESC=	Enable functionality to connect to MTPZ devices

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"
.endif

MTPZ_CONFIGURE_ENABLE=	mtpz
MTPZ_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

post-patch:
.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
	@${REINPLACE_CMD} -e \
		'/LIBUSB_REQUIRES/s|libusb-1.0||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/Libs.private/s|:|& @LIBUSB_LIBS@|' ${WRKSRC}/libmtp.pc.in
.endif
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=| ; \
		 /endian.h/s|machine|sys|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|Requires|&.private|' ${WRKSRC}/libmtp.pc.in
	@${REINPLACE_CMD} -e \
		's|__builtin_bswap|bswap|g' ${WRKSRC}/src/mtpz.c

.include <bsd.port.mk>
