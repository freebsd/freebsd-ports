PORTNAME=	mbgtools
DISTVERSION=	fbsd-1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meinberg.de/download/drivers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and tools for Meinberg PTP/GPS cards

LICENSE=	BSD2CLAUSE

BROKEN_mips64=		fails to compile: unused variables
BROKEN_sparc64=		fails to compile: error in structure definitions

USES=		kmod uidfix
USE_RC_SUBR=	mbgsvcd

.include <bsd.port.mk>
