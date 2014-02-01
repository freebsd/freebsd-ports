# Created by: Kueifeng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	vordog
PORTVERSION=	20080708
CATEGORIES=	sysutils
MASTER_SITES=	http://www.assembla.com/spaces/vordog/documents/dcR7vqtqyr3AMlab7jnrAJ/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Watchdog(9) driver for watchdog timer of Vortex86

ONLY_FOR_ARCHS=	i386
USES=		kmod

do-install:
	${INSTALL_KLD} ${WRKSRC}/vordog.ko ${STAGEDIR}${KMODDIR}

.include <bsd.port.mk>
