# New ports collection makefile for:	razor-agents
# Date created:				29 November 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	razor-agents
PORTVERSION=	2.36
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	razor

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A distributed, collaborative, spam detection and filtering network

BUILD_DEPENDS=	${SITE_PERL}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Digest/Nilsimsa.pm:${PORTSDIR}/security/p5-Digest-Nilsimsa \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		razor-revoke.1 razor-admin.1 razor-report.1 razor-check.1
MAN3=		Razor2::Errorhandler.3 Razor2::Preproc::deHTMLxs.3 \
		Razor2::Syslog.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@${PREFIX}/bin/razor-client

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
MAN5=		razor-agents.5 razor-whitelist.5 razor-agent.conf.5
.endif

.include <bsd.port.post.mk>
