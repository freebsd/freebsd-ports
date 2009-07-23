# Ports collection makefile for:       Perl::Critic::Bangs
# Date created:                        Jun 06, 2008
# Whom:                                Vany <ivan@serezhkin.com>
#
# $FreeBSD$

PORTNAME=	Perl-Critic-Bangs
PORTVERSION=	1.02
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ivan@serezhkin.com
COMMENT=	A collection of handy Perl::Critic policies

BUILD_DEPENDS=	${SITE_PERL}/Perl/Critic.pm:${PORTSDIR}/textproc/p5-Perl-Critic
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.8+

MAN3=	Perl::Critic::Bangs.3 \
	Perl::Critic::Policy::Bangs::ProhibitUselessRegexModifiers.3 \
	Perl::Critic::Policy::Bangs::ProhibitNoPlan.3 \
	Perl::Critic::Policy::Bangs::ProhibitFlagComments.3 \
	Perl::Critic::Policy::Bangs::ProhibitNumberedNames.3 \
	Perl::Critic::Policy::Bangs::ProhibitRefProtoOrProto.3 \
	Perl::Critic::Policy::Bangs::ProhibitVagueNames.3 \
	Perl::Critic::Policy::Bangs::ProhibitCommentedOutCode.3

.include <bsd.port.mk>
