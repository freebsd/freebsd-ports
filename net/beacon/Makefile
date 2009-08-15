# New ports collection makefile for:	beacon
# Date created:		26 February 2004
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	beacon
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	net perl5 mbone ipv6
MASTER_SITES=	http://dast.nlanr.net/Projects/Beacon/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Beacon active measurement tool to monitor multicast

BUILD_DEPENDS=	${SITE_PERL}/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}
USE_PERL5=	yes
USE_AUTOTOOLS=	autoconf:262
USE_RC_SUBR=	beacon

.ifdef(WITHOUT_IPV6)
CONFIGURE_ARGS=
.else
#enable IPv6 name lookup, and sending IPv6 multicast
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_beacon.in
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-install:
	@${ECHO} "Sample config installed at \
	${PREFIX}/etc/beacon.conf.sample"
	@${ECHO} "Copy the customised version to ${PREFIX}/etc/beacon.conf"
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
