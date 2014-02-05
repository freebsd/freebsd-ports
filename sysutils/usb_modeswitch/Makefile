# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usb_modeswitch
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.draisberghof.de/usb_modeswitch/
DISTNAME=	${PORTNAME:S|_|-|}-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Handling Mode-Switching USB Devices

LICENSE=	GPLv2

USE_BZIP2=	yes

pre-patch:
		${REINPLACE_CMD} 's/gcc/${CC}/' ${WRKSRC}/Makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/usb_modeswitch ${STAGEDIR}${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/usb_modeswitch.conf ${STAGEDIR}${PREFIX}/etc/usb_modeswitch.conf.sample
		${INSTALL_MAN} ${WRKSRC}/usb_modeswitch.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
