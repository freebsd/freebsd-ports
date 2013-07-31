# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session
PORTVERSION=	0.37
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic Catalyst Session plugin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.71001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0.76:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0.00801:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Object-Signature>=0:${PORTSDIR}/devel/p5-Object-Signature \
		p5-namespace-clean>=0.10:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize-PSGI>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-PSGI

USES=		perl5
USE_PERL5=	configure extract

MAN3=		Catalyst::Plugin::Session.3 \
		Catalyst::Plugin::Session::State.3 \
		Catalyst::Plugin::Session::Store.3 \
		Catalyst::Plugin::Session::Store::Dummy.3 \
		Catalyst::Plugin::Session::Test::Store.3 \
		Catalyst::Plugin::Session::Tutorial.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^(is_upgrading_needed|test_requires)/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
