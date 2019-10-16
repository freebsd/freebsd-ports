# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	lsdvd
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print information about the contents and structure of a DVD

LICENSE=	GPLv2

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

USES=		pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/lsdvd \
		man/man1/lsdvd.1.gz

WITH_DVD_DEVICE?=/dev/cd0

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${WITH_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
	@${ECHO_MSG} "===>"

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/dvd|${WITH_DVD_DEVICE}|' \
		${WRKSRC}/lsdvd.c

.include <bsd.port.mk>
