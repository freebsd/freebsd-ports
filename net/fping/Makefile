# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	fping
PORTVERSION=	4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jharris@widomaker.com
COMMENT=	Quickly ping multiple hosts without flooding the network

LICENSE=	PreviousBSD
LICENSE_GROUPS=	FSF
LICENSE_NAME=	Previous BSD License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf gmake
USE_GITHUB=	yes
GH_ACCOUNT=	schweikert

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/sbin" \
		--enable-ipv4
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	IPV6
OPTIONS_SUB=	yes
IPV6_CONFIGURE_OFF=--disable-ipv6

post-install-IPV6-on:
	${RLN} ${STAGEDIR}${PREFIX}/sbin/fping  ${STAGEDIR}${PREFIX}/sbin/fping6
	${RLN} ${STAGEDIR}${PREFIX}/man/man8/fping.8 ${STAGEDIR}${PREFIX}/man/man8/fping6.8

.include <bsd.port.mk>
