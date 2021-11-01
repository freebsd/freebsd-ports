# Created by: Roy Marples <roy@marples.name>

PORTNAME=	dhcpcd
DISTVERSION=	9.4.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/downloads/dhcpcd/

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe tar:xz
CPE_VENDOR=	dhcpcd_project
USE_RC_SUBR=	dhcpcd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples \
		--prefix=${PREFIX} \
		--privsepuser="_dhcp" \
		--without-udev

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd

.include <bsd.port.mk>
