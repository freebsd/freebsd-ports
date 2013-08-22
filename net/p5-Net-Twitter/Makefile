# Created by: clsung
# $FreeBSD$

PORTNAME=	Net-Twitter
PORTVERSION=	4.00007
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to twitter.com

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0.50:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-DateTime>=0.51:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=1.09:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Devel-StackTrace>=1.21:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>=0.9:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Aliases>=0:${PORTSDIR}/devel/p5-MooseX-Aliases \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-Net-OAuth>=0.25:${PORTSDIR}/net/p5-Net-OAuth \
		p5-Try-Tiny>=0.03:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=1.40:${PORTSDIR}/net/p5-URI \
		p5-libwww>=2.032:${PORTSDIR}/www/p5-libwww \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::Identica.3 \
		Net::Twitter.3 \
		Net::Twitter::API.3 \
		Net::Twitter::Core.3 \
		Net::Twitter::Error.3 \
		Net::Twitter::Manual::MigratingToV1_1.3 \
		Net::Twitter::OAuth.3 \
		Net::Twitter::Role::API::Lists.3 \
		Net::Twitter::Role::API::REST.3 \
		Net::Twitter::Role::API::RESTv1_1.3 \
		Net::Twitter::Role::API::Search.3 \
		Net::Twitter::Role::API::Search::Trends.3 \
		Net::Twitter::Role::API::TwitterVision.3 \
		Net::Twitter::Role::API::Upload.3 \
		Net::Twitter::Role::AutoCursor.3 \
		Net::Twitter::Role::InflateObjects.3 \
		Net::Twitter::Role::Legacy.3 \
		Net::Twitter::Role::OAuth.3 \
		Net::Twitter::Role::RateLimit.3 \
		Net::Twitter::Role::RetryOnError.3 \
		Net::Twitter::Role::SimulateCursors.3 \
		Net::Twitter::Role::WrapError.3 \
		Net::Twitter::Search.3

.include <bsd.port.mk>
