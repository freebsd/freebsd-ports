# New ports collection makefile for:	razor-agents
# Date created:				29 November 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	razor-agents
PORTVERSION=	2.21
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	razor

MAINTAINER=	leeym@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/Nilsimsa.pm:${PORTSDIR}/security/p5-Digest-Nilsimsa \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		razor-revoke.1 razor-admin.1 razor-report.1 razor-check.1
MAN3=		Razor2::Errorhandler.3 Razor2::Preproc::deHTMLxs.3 \
		Razor2::Syslog.3
MAN5=		razor-agents.5 razor-whitelist.5 razor-agent.conf.5

post-install:
	@${PREFIX}/bin/razor-client

.include <bsd.port.pre.mk>

PERL_MAJOR=${PERL_VER:C|^([1-9]+).*|\1|}
PERL_MINOR=${PERL_VER:C|^[1-9]+\.0*([1-9]+).*|\1|}

.if ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8
BUILD_DEPENDS+=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
