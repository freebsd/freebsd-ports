# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	8.1.1
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/downloads/dhcpcd/ \
		https://cflags.cc/roy/dhcpcd/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe tar:xz

CPE_VENDOR=	dhcpcd_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples
USE_RC_SUBR=	dhcpcd

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/share/examples/dhcpcd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd

.include <bsd.port.mk>
