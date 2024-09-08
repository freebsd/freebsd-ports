PORTNAME=	dhcpcd
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0.10
CATEGORIES=	net

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client
WWW=		https://roy.marples.name/projects/dhcpcd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe
CPE_VENDOR=	dhcpcd_project
USE_GITHUB=	yes
GH_ACCOUNT=	NetworkConfiguration
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
