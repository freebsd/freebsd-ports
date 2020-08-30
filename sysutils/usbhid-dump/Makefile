# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbhid-dump
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/DIGImend/usbhid-dump/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	USB HID device dumping utility

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		libtool pkgconfig

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/uhd/
	cd ${WRKSRC}/include/uhd/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/uhd/
	${INSTALL_DATA} ${WRKSRC}/lib/.libs/libuhd.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
