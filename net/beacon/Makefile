# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	beacon
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net perl5 mbone ipv6
MASTER_SITES=	SF/multicastbeacon/multicastbeacon/beacon%20v${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Beacon active measurement tool to monitor multicast

BUILD_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}
USE_PERL5=	yes
USE_AUTOTOOLS=	autoconf

OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=

IPV6_DESC=		Enable IPv6 PTR lookups

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
BUILD_DEPENDS+=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
