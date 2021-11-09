# Created by: Roy Marples <roy@marples.name>

PORTNAME=	dhcpcd
DISTVERSION=	9.4.1
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/downloads/dhcpcd/

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe tar:xz
CPE_VENDOR=	dhcpcd_project
USE_RC_SUBR=	dhcpcd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples \
		--privsepuser="_dhcp" \
		--without-udev

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/share/examples/dhcpcd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd
	${MKDIR} ${STAGEDIR}/var/db/dhcpcd

.include <bsd.port.mk>
