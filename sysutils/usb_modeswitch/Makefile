# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usb_modeswitch
PORTVERSION=	2.6.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.draisberghof.de/usb_modeswitch/
DISTNAME=	${PORTNAME:S|_|-|}-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2 \
		${DATANAME}.tar.bz2

MAINTAINER=	franco@opnsense.org
COMMENT=	Handling Mode-Switching USB Devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DATAVERSION=	20191128
DATANAME=	${PORTNAME:S|_|-|}-data-${DATAVERSION}

USES=		gmake tar:bzip2

pre-patch:
	${REINPLACE_CMD} 's|gcc|${CC}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} 's|`pkg-config --libs --cflags libusb-1.0`|-lusb|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usb_modeswitch ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/usb_modeswitch.conf ${STAGEDIR}${PREFIX}/etc/usb_modeswitch.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usb_modeswitch.1 ${STAGEDIR}${PREFIX}/man/man1
	cd ${WRKSRC}/../${DATANAME}/usb_modeswitch.d && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
