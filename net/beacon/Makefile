# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	beacon
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	net perl5 mbone
MASTER_SITES=	SF/multicastbeacon/multicastbeacon/beacon%20v${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Beacon active measurement tool to monitor multicast

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		perl5
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS IPV6

IPV6_DESC=		Enable IPv6 PTR lookups
IPV6_CONFIGURE_ENABLE=	ipv6
IPV6_BUILD_DEPENDS=	p5-Socket6>=0:net/p5-Socket6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Multicast/Beacon/Beacon.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
