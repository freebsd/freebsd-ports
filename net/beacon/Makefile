# New ports collection makefile for:	beacon
# Date created:		26 February 2004
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	beacon
PORTVERSION=	0.9.06
PORTREVISION=	1
CATEGORIES=	net perl5 mbone ipv6
MASTER_SITES=	http://dast.nlanr.net/Projects/Beacon/Releases/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Beacon active measurement tool to monitor multicast

BUILD_DEPENDS=	${SITE_PERL}/Net/Domain.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

WWW_DIR?=	${PREFIX}/www/
PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

do-build:
	#Build unreleased NET::RTP perl module
	cd ${WRKSRC}/Net-RTP-0.4/ ; \
	./configure --enable-ipv6 ; \
	${PERL} Makefile.PL ; \
	make

do-install:
	#Install unreleased NET::RTP perl module
	cd ${WRKSRC}/Net-RTP-0.4/ ; \
	make install
	#Install the Beacon itself
	${MKDIR} ${WWW_DIR}/${PORTNAME}-${PORTVERSION}
	${INSTALL_SCRIPT} ${WRKSRC}/beacon.pl ${WWW_DIR}/${PORTNAME}-${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/beacon.conf ${PREFIX}/etc/beacon.conf.sample
	@${ECHO} ""
	@${ECHO} "Sample config installed at \
		${PREFIX}/etc/beacon.conf.sample"
	@${ECHO} "Copy the customised version to ${PREFIX}/etc/beacon.conf"

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
