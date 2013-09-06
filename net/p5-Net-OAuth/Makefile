# ex:ts=8
# Ports collection makefile for:	Net::OAuth
# Date created:			Oct 24, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-OAuth
PORTVERSION=	0.28
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	An implementation of the OAuth protocol

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0.06:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Digest-HMAC>=1.01:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Net::OAuth.3 \
	Net::OAuth::AccessToken.3 \
	Net::OAuth::AccessTokenRequest.3 \
	Net::OAuth::AccessTokenResponse.3 \
	Net::OAuth::Client.3 \
	Net::OAuth::ConsumerRequest.3 \
	Net::OAuth::Message.3 \
	Net::OAuth::ProtectedResourceRequest.3 \
	Net::OAuth::Request.3 \
	Net::OAuth::RequestTokenRequest.3 \
	Net::OAuth::RequestTokenResponse.3 \
	Net::OAuth::Response.3 \
	Net::OAuth::SignatureMethod::HMAC_SHA1.3 \
	Net::OAuth::SignatureMethod::HMAC_SHA256.3 \
	Net::OAuth::SignatureMethod::PLAINTEXT.3 \
	Net::OAuth::SignatureMethod::RSA_SHA1.3 \
	Net::OAuth::UserAuthRequest.3 \
	Net::OAuth::UserAuthResponse.3 \
	Net::OAuth::V1_0A::AccessTokenRequest.3 \
	Net::OAuth::V1_0A::RequestTokenRequest.3 \
	Net::OAuth::V1_0A::RequestTokenResponse.3 \
	Net::OAuth::V1_0A::UserAuthResponse.3 \
	Net::OAuth::XauthAccessTokenRequest.3 \
	Net::OAuth::YahooAccessTokenRefreshRequest.3

.include <bsd.port.mk>
