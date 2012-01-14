# New ports collection makefile for:	usb_modeswitch
# Date created:				14 January 2011
# Whom:					Alexander V. Chernikov <melifaro@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	usb_modeswitch
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.draisberghof.de/usb_modeswitch/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Handling Mode-Switching USB Devices

LICENSE=	GPLv2

MAKE_JOBS_UNSAFE=	yes

MAN1=		usb_modeswitch.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/usb_modeswitch ${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/usb_modeswitch.conf ${PREFIX}/etc/usb_modeswitch.conf.sample
		${INSTALL_MAN} ${WRKSRC}/usb_modeswitch.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
