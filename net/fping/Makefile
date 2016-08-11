# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	fping
PORTVERSION=	3.10
CATEGORIES=	net ipv6
MASTER_SITES=	http://fping.org/dist/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Quickly ping multiple hosts without flooding the network

LICENSE=	PreviousBSD
LICENSE_GROUPS=	FSF
LICENSE_NAME=	Previous BSD License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_MULTI=		NET
OPTIONS_MULTI_NET=	IPV4 IPV6
OPTIONS_DEFAULT=	IPV4
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/sbin"
INSTALL_TARGET=	install-strip

IPV4_CONFIGURE_ENABLE=	ipv4
IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.mk>
