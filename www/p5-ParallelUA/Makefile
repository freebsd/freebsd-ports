# New ports collection makefile for:    p5-Parallel-UA
# Date created:                         Sep 8 1998
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	ParallelUA
PORTVERSION=	2.57
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	LWP
PKGNAMEPREFIX=	p5-
DISTNAME=	ParallelUserAgent-${PORTVERSION}

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Perl5 Parallel LWP User Agent for WWW access

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Bundle::ParallelUA.3 \
		LWP::Parallel.3 \
		LWP::Parallel::Protocol.3 \
		LWP::Parallel::RobotUA.3 \
		LWP::Parallel::UserAgent.3 \
		LWP::ParallelUA.3 \
		LWP::RobotPUA.3

.include <bsd.port.mk>
