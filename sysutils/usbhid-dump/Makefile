# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbhid-dump
PORTVERSION=	1.4
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	USB HID device dumping utility

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig

GH_ACCOUNT=	DIGImend
USE_GITHUB=	yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/uhd/
	cd ${WRKSRC}/include/uhd/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/uhd/
	${INSTALL_DATA} ${WRKSRC}/lib/.libs/libuhd.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
