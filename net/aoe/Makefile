# Created by: Stacey D. Son <sds@son.org>
# $FreeBSD$

PORTNAME=	aoe
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	net kld
MASTER_SITES=	http://www.son.org/download/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FreeBSD driver for ATA over Ethernet (AoE)

SSP_UNSAFE=	kernel module does not support ssp

USES=	kmod

WRKSRC=		${WRKDIR}/dev/aoe
KMODDIR=	${PREFIX}/lib/aoe

USE_RC_SUBR=	aoe

do-install:
	${INSTALL_KLD} ${WRKSRC}/aoe.ko ${STAGEDIR}${PREFIX}/lib/aoe
	${INSTALL_MAN} ${WRKDIR}/aoe.4 ${STAGEDIR}${PREFIX}/man/man4/

.include <bsd.port.mk>
