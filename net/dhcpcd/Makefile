# Created by: Roy Marples <roy@marples.name>
# $FreeBSD$

PORTNAME=	dhcpcd
PORTVERSION=	6.5.1
CATEGORIES=	net
MASTER_SITES=	http://roy.marples.name/downloads/dhcpcd/ \
		LOCAL/delphij

MAINTAINER=	roy@marples.name
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
GNU_CONFIGURE=	yes
USE_RC_SUBR=	dhcpcd

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpcd.conf.sample

.include <bsd.port.mk>
