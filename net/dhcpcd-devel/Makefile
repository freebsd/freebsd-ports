# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	8.99.0.g20191220
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/cgit/dhcpcd.git/snapshot/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${GITTAG}
GITTAG=		81e7d0a

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	dhcpcd-[0-9]*

USES=		compiler:c11 cpe tar:xz

CPE_VENDOR=	dhcpcd_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples \
		--privsepuser="_dhcp"
USE_RC_SUBR=	dhcpcd

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/share/examples/dhcpcd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd
	${MKDIR} ${STAGEDIR}/var/run/dhcpcd

.include <bsd.port.mk>
