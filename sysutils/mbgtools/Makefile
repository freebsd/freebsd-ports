# Created by: George Neville-Neil gnn@freebsd.org
# $FreeBSD$

PORTNAME=	mbgtools
DISTVERSION=	fbsd-dev-2013-06-26
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meinberg.de/download/drivers/

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Drivers and tools for Meinberg PTP/GPS cards

LICENSE=	BSD

USES=		kmod

USE_RC_SUBR=	mbgsvcd

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${WRKSRC}/scripts/mbgsvcd ${FILESDIR}/mbgsvcd.in

.include <bsd.port.post.mk>
