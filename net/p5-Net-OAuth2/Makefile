# New ports collection makefile for:	p5-Net-OAuth2
# Date created:		2012-04-30
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OAuth2
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 2.0 for Perl

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Mock-LWP-Dispatch>=0:${PORTSDIR}/devel/p5-Test-Mock-LWP-Dispatch \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1.22:${PORTSDIR}/devel/p5-Test-Pod \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=		Net::OAuth2.3 \
		Net::OAuth2::AccessToken.3 \
		Net::OAuth2::Client.3 \
		Net::OAuth2::Profile::Base.3 \
		Net::OAuth2::Profile::WebServer.3

.include <bsd.port.mk>
