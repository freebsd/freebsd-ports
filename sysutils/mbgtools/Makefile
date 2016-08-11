# Created by: George Neville-Neil gnn@freebsd.org
# $FreeBSD$

PORTNAME=	mbgtools
DISTVERSION=	fbsd-dev-2013-06-26
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meinberg.de/download/drivers/

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Drivers and tools for Meinberg PTP/GPS cards

LICENSE=	BSD

BROKEN_powerpc64=	Does not build

USE_RC_SUBR=	mbgsvcd

USES=		kmod uidfix

BROKEN_arm=	cannot compile: unused variables
BROKEN_sparc64=	cannot compile: error in structure definitions

.include <bsd.port.mk>
