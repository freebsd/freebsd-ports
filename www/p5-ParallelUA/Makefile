# New ports collection makefile for:    p5-Parallel-UA
# http://www.cs.washington.edu/homes/marclang/ParallelUA/
# Date created:                         Sep 8 1998
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	ParallelUA
PORTVERSION=	2.49
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	LWP
PKGNAMEPREFIX=	p5-
DISTNAME=	ParallelUserAgent-${PORTVERSION}

MAINTAINER=	ache@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

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
