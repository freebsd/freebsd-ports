# Created by: Stacey D. Son <sds@son.org>
# $FreeBSD$

PORTNAME=	aoe
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.son.org/download/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FreeBSD driver for ATA over Ethernet (AoE)

BROKEN_aarch64=		fails to compile: redefinition of frame
BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99
BROKEN_armv7=		fails to compile: redefinition of frame
BROKEN_sparc64=		fails to compile: redefinition of frame

USES=	kmod

WRKSRC=		${WRKDIR}/dev/aoe
KMODDIR=	${PREFIX}/lib/aoe

USE_RC_SUBR=	aoe

do-install:
	${INSTALL_KLD} ${WRKSRC}/aoe.ko ${STAGEDIR}${PREFIX}/lib/aoe
	${INSTALL_MAN} ${WRKDIR}/aoe.4 ${STAGEDIR}${PREFIX}/man/man4/

.include <bsd.port.mk>
