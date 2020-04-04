# $FreeBSD$

PORTNAME=	libsmacker
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${DISTNAME}/

MAINTAINER=	kennedy.greg@gmail.com
COMMENT=	C library for decoding .smk Smacker Video files

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libsmacker.so

post-patch:
	@${REINPLACE_CMD} '/CFLAGS/s|+=|?=|; s|gcc|${CC}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
