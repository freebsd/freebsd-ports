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

MAKE_JOBS_UNSAFE=	yes

MAN1=		usb_modeswitch.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/usb_modeswitch ${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/usb_modeswitch.conf ${PREFIX}/etc/usb_modeswitch.conf.sample
		${INSTALL_MAN} ${WRKSRC}/usb_modeswitch.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
