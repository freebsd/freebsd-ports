# New ports collection makefile for:	OAuth::Lite
# Date created:		03 Feb 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OAuth-Lite
PORTVERSION=	1.30
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/L/LY/LYOKATO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for OAuth framework

RUN_DEPENDS=	\
	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Class-Data-Accessor>=0.04001:${PORTSDIR}/devel/p5-Class-Data-Accessor \
	p5-Class-ErrorHandler>=0.01:${PORTSDIR}/devel/p5-Class-ErrorHandler \
	p5-Crypt-OpenSSL-RSA>=0.25:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
	p5-Crypt-OpenSSL-Random>=0.04:${PORTSDIR}/security/p5-Crypt-OpenSSL-Random \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-List-MoreUtils>=0.21:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-UNIVERSAL-require>=0.11:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-URI>=1.35:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	OAuth::Lite.3 \
	OAuth::Lite::Agent.3 \
	OAuth::Lite::AuthMethod.3 \
	OAuth::Lite::Consumer.3 \
	OAuth::Lite::Problems.3 \
	OAuth::Lite::Response.3 \
	OAuth::Lite::Server::Test::Echo.3 \
	OAuth::Lite::Server::mod_perl2.3 \
	OAuth::Lite::ServerUtil.3 \
	OAuth::Lite::SignatureMethod.3 \
	OAuth::Lite::SignatureMethod::HMAC_SHA1.3 \
	OAuth::Lite::SignatureMethod::PLAINTEXT.3 \
	OAuth::Lite::SignatureMethod::RSA_SHA1.3 \
	OAuth::Lite::Token.3 \
	OAuth::Lite::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
