# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	fping
PORTVERSION=	3.13
CATEGORIES=	net ipv6

MAINTAINER=	jharris@widomaker.com
COMMENT=	Quickly ping multiple hosts without flooding the network

LICENSE=	PreviousBSD
LICENSE_GROUPS=	FSF
LICENSE_NAME=	Previous BSD License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	schweikert

OPTIONS_MULTI=		NET
OPTIONS_MULTI_NET=	IPV4 IPV6
OPTIONS_DEFAULT=	IPV4
OPTIONS_SUB=	yes

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/sbin"
INSTALL_TARGET=	install-strip

IPV4_CONFIGURE_ENABLE=	ipv4
IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.mk>
