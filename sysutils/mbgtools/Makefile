# Created by: George Neville-Neil gnn@freebsd.org
# $FreeBSD$

PORTNAME=	mbgtools
DISTVERSION=	fbsd-dev-2013-06-26
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meinberg.de/download/drivers/

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Drivers and tools for Meinberg PTP/GPS cards

LICENSE=	BSD

USE_RC_SUBR=	mbgsvcd

USES=		kmod uidfix

BROKEN_aarch64=		cannot compile: unused variables
BROKEN_mips64=		cannot compile: unused variables
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		cannot compile: error in structure definitions

.include <bsd.port.mk>
