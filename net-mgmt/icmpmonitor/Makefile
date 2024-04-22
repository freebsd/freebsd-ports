PORTNAME=	icmpmonitor
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple host icmp monitoring tool
WWW=		https://www.crocodile.org/software.html

LICENSE=	GPLv2 BSD4CLAUSE
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	share/man/man1/icmpmonitor.1.gz sbin/icmpmonitor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/icmpmonitor

.include <bsd.port.mk>
