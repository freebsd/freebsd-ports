# Created by: Vany <ivan@serezhkin.com>
# $FreeBSD$

PORTNAME=	Perl-Critic-Bangs
PORTVERSION=	1.08
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ivan@serezhkin.com
COMMENT=	A collection of handy Perl::Critic policies

BUILD_DEPENDS=	p5-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Perl-Critic
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Perl-Critic-Deprecated>=0:${PORTSDIR}/devel/p5-Perl-Critic-Deprecated

USES=		perl5
USE_PERL5=	configure

MAN3=	Perl::Critic::Bangs.3 \
	Perl::Critic::Policy::Bangs::ProhibitUselessRegexModifiers.3 \
	Perl::Critic::Policy::Bangs::ProhibitNoPlan.3 \
	Perl::Critic::Policy::Bangs::ProhibitFlagComments.3 \
	Perl::Critic::Policy::Bangs::ProhibitNumberedNames.3 \
	Perl::Critic::Policy::Bangs::ProhibitRefProtoOrProto.3 \
	Perl::Critic::Policy::Bangs::ProhibitVagueNames.3 \
	Perl::Critic::Policy::Bangs::ProhibitCommentedOutCode.3 \
	Perl::Critic::Policy::Bangs::ProhibitBitwiseOperators.3

.include <bsd.port.mk>
