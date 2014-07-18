# Created by: Petar Zhivkov Petrov <pesho.petrov@gmail.com>
# $FreeBSD$

PORTNAME=	libmtp
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=	MTPZ
MTPZ_DESC=	Enable functionality to connect to MTPZ devices

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV+=	LIBUSB_CFLAGS=" " LIBUSB_LIBS="-lusb"

MTPZ_CONFIGURE_ENABLE=	mtpz
MTPZ_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=| ; \
		 /LIBUSB_REQUIRES/s|libusb-1.0|| ; \
		 /endian.h/s|machine|sys|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<libusb-1.0/|<|' ${WRKSRC}/src/libusb-glue.h
	@${REINPLACE_CMD} -e \
		's|__builtin_bswap|bswap|g' ${WRKSRC}/src/mtpz.c

.include <bsd.port.mk>
