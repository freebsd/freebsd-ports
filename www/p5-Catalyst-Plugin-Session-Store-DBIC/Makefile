# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-Store-DBIC
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Store your sessions via DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Session-Store-Delegate>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-Delegate \
		p5-DBIx-Class>=0.0700:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Plugin::Session::Store::DBIC.3 \
	Catalyst::Plugin::Session::Store::DBIC::Delegate.3

.include <bsd.port.mk>
