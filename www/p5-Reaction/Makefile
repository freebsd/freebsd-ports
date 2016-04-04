# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Reaction
PORTVERSION=	0.002005
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extended MVC framework built upon Catalyst

BUILD_DEPENDS=	p5-Catalyst-Component-ACCEPT_CONTEXT>=0.05:www/p5-Catalyst-Component-ACCEPT_CONTEXT \
		p5-Catalyst-Component-InstancePerContext>=0.001001:www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Model-DBIC-Schema>=0.23:www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Plugin-ConfigLoader>=0.23:www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-I18N>=0.09:www/p5-Catalyst-Plugin-I18N \
		p5-Catalyst-Plugin-Static-Simple>=0.21:www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Runtime>=5.80002:www/p5-Catalyst-Runtime \
		p5-Catalyst-View-TT>=0.29:www/p5-Catalyst-View-TT \
		p5-Config-General>=2.42:devel/p5-Config-General \
		p5-Crypt-Eksblowfish>=0.005:security/p5-Crypt-Eksblowfish \
		p5-DBIx-Class-IntrospectableM2M>=0.001001:databases/p5-DBIx-Class-IntrospectableM2M \
		p5-DBIx-Class>=0.08100:databases/p5-DBIx-Class \
		p5-DateTime-Event-Recurrence>=0.16:devel/p5-DateTime-Event-Recurrence \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set \
		p5-DateTime>=0.47:devel/p5-DateTime \
		p5-Devel-Declare>=0.005000:devel/p5-Devel-Declare \
		p5-Email-Valid>=0.181:mail/p5-Email-Valid \
		p5-File-ShareDir>=1:devel/p5-File-ShareDir \
		p5-JSON>=0:converters/p5-JSON \
		p5-Method-Signatures-Simple>=0.03:devel/p5-Method-Signatures-Simple \
		p5-Moose>=0.74:devel/p5-Moose \
		p5-MooseX-MethodAttributes>=0.18:devel/p5-MooseX-MethodAttributes \
		p5-MooseX-Role-Parameterized>=0.24:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types-Common>=0.001000:devel/p5-MooseX-Types-Common \
		p5-MooseX-Types-DateTime>=0.03:devel/p5-MooseX-Types-DateTime \
		p5-MooseX-Types-URI>=0.02:devel/p5-MooseX-Types-URI \
		p5-MooseX-Types>=0.10:devel/p5-MooseX-Types \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Sub-Exporter>=0.982:devel/p5-Sub-Exporter \
		p5-Sub-Name>=0.04:devel/p5-Sub-Name \
		p5-Template-Toolkit>=2.20:www/p5-Template-Toolkit \
		p5-Time-modules>=2006.0814:devel/p5-Time-modules \
		p5-URI>=1.37:net/p5-URI \
		p5-aliased>=0.22:devel/p5-aliased \
		p5-namespace-clean>=0.11:devel/p5-namespace-clean \
		p5-signatures>=0.05:lang/p5-signatures
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-SQL-Translator>=0.11002:databases/p5-SQL-Translator \
		p5-Test-Class>=0.31:devel/p5-Test-Class \
		p5-Test-Memory-Cycle>=1.04:devel/p5-Test-Memory-Cycle \
		p5-Test-WWW-Mechanize-Catalyst>=0.51:devel/p5-Test-WWW-Mechanize-Catalyst

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
