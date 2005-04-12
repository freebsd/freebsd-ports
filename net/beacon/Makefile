# New ports collection makefile for:	beacon
# Date created:		26 February 2004
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	beacon
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net perl5 mbone ipv6
MASTER_SITES=	http://dast.nlanr.net/Projects/Beacon/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Beacon active measurement tool to monitor multicast

BUILD_DEPENDS=	${SITE_PERL}/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}
USE_PERL5=	yes
USE_AUTOCONF_VER=	259
CONFIGURE_ARGS=	--bindir=${WWW_DIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.ifdef(WITH_IPV6)
#enable IPv6 name lookup, and sending IPv6 multicast
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_beacon.in
CONFUGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
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
