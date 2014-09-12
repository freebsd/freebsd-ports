# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	beacon
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	net perl5 mbone ipv6
MASTER_SITES=	SF/multicastbeacon/multicastbeacon/beacon%20v${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Beacon active measurement tool to monitor multicast

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}

USES=		perl5
USE_PERL5+=	fixpacklist
USE_AUTOTOOLS=	autoconf
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS IPV6

IPV6_DESC=		Enable IPv6 PTR lookups
IPV6_CONFIGURE_ENABLE=	ipv6
IPV6_BUILD_DEPENDS=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Net/Multicast/Beacon/Beacon.so
	${RM} ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
