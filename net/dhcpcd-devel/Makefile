# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	g20200616
CATEGORIES=	net
MASTER_SITES=	https://roy.marples.name/cgit/dhcpcd.git/snapshot/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${GITTAG}
GITTAG=		6ae7a01

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	dhcpcd

USES=		compiler:c11 cpe tar:xz

CPE_VENDOR=	dhcpcd_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples \
		--privsepuser="_dhcp" \
		--without-udev
USE_RC_SUBR=	dhcpcd

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/share/examples/dhcpcd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd
	${MKDIR} ${STAGEDIR}/var/db/dhcpcd

.include <bsd.port.mk>
