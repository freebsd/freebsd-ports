# $FreeBSD$

PORTNAME=	wireguard-kmod
PORTVERSION=	0.0.20210319
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-freebsd/snapshot/
DISTNAME=	wireguard-freebsd-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation for the FreeBSD kernel

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/COPYING

IGNORE_FreeBSD_11=	only for FreeBSD 12.1 and newer

USES=		kmod tar:xz uidfix

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	${KMODDIR}/if_wg.ko

.include <bsd.port.mk>
