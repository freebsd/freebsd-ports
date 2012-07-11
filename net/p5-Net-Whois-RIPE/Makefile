# Ports collection makefile for:	p5-Net-Whois-RIPE
# Date created:			Sep 11, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	2.00013
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AASSAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Iterator-Util>=0:${PORTSDIR}/devel/p5-Iterator-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize

PERL_CONFIGURE=	yes

MAN3=		Net::Whois::Object.3 \
		Net::Whois::Object::AsBlock.3 \
		Net::Whois::Object::AsSet.3 \
		Net::Whois::Object::AutNum.3 \
		Net::Whois::Object::Domain.3 \
		Net::Whois::Object::FilterSet.3 \
		Net::Whois::Object::Inet6Num.3 \
		Net::Whois::Object::InetNum.3 \
		Net::Whois::Object::InetRtr.3 \
		Net::Whois::Object::Information.3 \
		Net::Whois::Object::Irt.3 \
		Net::Whois::Object::KeyCert.3 \
		Net::Whois::Object::Limerick.3 \
		Net::Whois::Object::Mntner.3 \
		Net::Whois::Object::Organisation.3 \
		Net::Whois::Object::PeeringSet.3 \
		Net::Whois::Object::Person.3 \
		Net::Whois::Object::Poem.3 \
		Net::Whois::Object::PoeticForm.3 \
		Net::Whois::Object::Response.3 \
		Net::Whois::Object::Role.3 \
		Net::Whois::Object::Route.3 \
		Net::Whois::Object::Route6.3 \
		Net::Whois::Object::RouteSet.3 \
		Net::Whois::Object::RtrSet.3 \
		Net::Whois::RIPE.3

.include <bsd.port.mk>
