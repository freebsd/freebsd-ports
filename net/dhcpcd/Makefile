# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	7.0
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	roy@marples.name
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USES=		cpe tar:xz
CPE_VENDOR=	dhcpcd_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples
USE_OPENRC_SUBR=dhcpcd

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	dhcpcd
GH_TAGNAME=	6fd3d98507ee18dce98bd58220d4ad1462ba6eae

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpcd.conf.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd

.include <bsd.port.mk>
