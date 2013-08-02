# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication
# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Authentication
PORTVERSION=	0.10019
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Infrastructure plugin for the Catalyst authentication framework

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0.10:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst

PORTSCOUT=	skipv:0.100092

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Authentication::Credential::Password.3 \
	Catalyst::Authentication::Credential::Remote.3 \
	Catalyst::Authentication::Realm.3 \
	Catalyst::Authentication::Realm::Compatibility.3 \
	Catalyst::Authentication::Realm::Progressive.3 \
	Catalyst::Authentication::Store.3 \
	Catalyst::Authentication::Store::Minimal.3 \
	Catalyst::Authentication::Store::Null.3 \
	Catalyst::Authentication::User.3 \
	Catalyst::Authentication::User::Hash.3 \
	Catalyst::Plugin::Authentication.3 \
	Catalyst::Plugin::Authentication::Credential::NoPassword.3  \
	Catalyst::Plugin::Authentication::Credential::Password.3 \
	Catalyst::Plugin::Authentication::Internals.3 \
	Catalyst::Plugin::Authentication::Store::Minimal.3 \
	Catalyst::Plugin::Authentication::User.3 \
	Catalyst::Plugin::Authentication::User::Hash.3

.include <bsd.port.mk>
