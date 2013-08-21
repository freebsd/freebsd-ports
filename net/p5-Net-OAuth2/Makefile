# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-OAuth2
PORTVERSION=	0.55
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 2.0 for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Mock-LWP-Dispatch>=0:${PORTSDIR}/devel/p5-Test-Mock-LWP-Dispatch \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1.22:${PORTSDIR}/devel/p5-Test-Pod \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USE_PERL5=	configure
USES=		perl5

MAN3=		Net::OAuth2.3 \
		Net::OAuth2::AccessToken.3 \
		Net::OAuth2::Client.3 \
		Net::OAuth2::Profile.3 \
		Net::OAuth2::Profile::Password.3 \
		Net::OAuth2::Profile::WebServer.3

.include <bsd.port.mk>
