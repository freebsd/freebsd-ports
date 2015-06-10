# Created by: nbm
# $FreeBSD$

PORTNAME=	icmpmonitor
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple host icmp monitoring tool

LICENSE=	GPLv2 BSD4CLAUSE
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes

PLIST_FILES=	man/man1/icmpmonitor.1.gz sbin/icmpmonitor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/icmpmonitor

.include <bsd.port.mk>
