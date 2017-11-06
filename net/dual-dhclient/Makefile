# $FreeBSD$

PORTNAME=	dual-dhclient
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Spawns dhclients for a dual-stack network

LICENSE=	PD

RUN_DEPENDS=	${LOCALBASE}/sbin/dhclient:net/isc-dhcp43-client

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/dual-dhclient

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dual-dhclient ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
