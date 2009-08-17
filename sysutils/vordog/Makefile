# Ports collection makefile for: vordog
# Date created: 8 July 2008
# Whom:		Kueifeng Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	vordog
PORTVERSION=	20080708
CATEGORIES=	sysutils kld
MASTER_SITES=	http://www.assembla.com/spaces/vordog/documents/dcR7vqtqyr3AMlab7jnrAJ/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Watchdog(9) driver for watchdog timer of Vortex86

KMODDIR=	/boot/modules

ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_KLD} ${WRKSRC}/vordog.ko ${KMODDIR}

.include <bsd.port.mk>
