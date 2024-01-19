PORTNAME=	mbgtools
DISTVERSION=	fbsd-1.0.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meinberg.de/download/drivers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and tools for Meinberg PTP/GPS cards
WWW=		https://www.meinbergglobal.com/english/sw/

LICENSE=	BSD2CLAUSE

BROKEN_mips64=		fails to compile: unused variables

USES=		kmod uidfix
USE_RC_SUBR=	mbgsvcd

.include <bsd.port.mk>
