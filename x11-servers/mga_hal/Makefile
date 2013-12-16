# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mga_hal
PORTVERSION=	4.4.0
PORTREVISION=	2
CATEGORIES=	x11-servers
MASTER_SITES=	ftp://ftp.matrox.com/pub/mga/archive/linux/%SUBDIR%/:i386,amd64
MASTER_SITE_SUBDIR=	2006/:i386 2006/64bit/:amd64
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:${ARCH}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Module for additional features with X.Org/XFree86 Matrox driver

RESTRICTED=	Matrox drivers may not be distributed.

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
DISTNAME=	matrox_driver-x86_32-${PORTVERSION}
.elif ${ARCH} == "amd64"
DISTNAME=	matrox_driver-x86_64-${PORTVERSION}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	YES
XORG_VERSION=	6.9.0

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/modules/drivers
	${INSTALL_DATA} ${WRKSRC}/xserver/${XORG_VERSION}/mga_hal_drv.so \
		${STAGEDIR}${PREFIX}/lib/modules/drivers/
	${INSTALL_DATA} ${WRKSRC}/xserver/${XORG_VERSION}/mga_drv.so \
		${STAGEDIR}${PREFIX}/lib/modules/drivers/

.include <bsd.port.post.mk>
