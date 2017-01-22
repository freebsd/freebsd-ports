# Created by: sanpei@FreeBSD.org
# $FreeBSD$

PORTNAME=	usbrh-libusb
PORTVERSION=	0.05
CATEGORIES=	misc
MASTER_SITES=	http://www.dd.iij4u.or.jp/~briareos/soft/ \
		LOCAL/sanpei
DISTNAME=	usbrh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another reads temperatures and humidity from a Strawberry Linux USB-RH

PLIST_FILES=	bin/usbrh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/usbrh ${STAGEDIR}${PREFIX}/bin/usbrh

.include <bsd.port.mk>
