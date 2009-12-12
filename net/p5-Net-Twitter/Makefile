# New ports collection makefile for:	p5-Net-Twitter
# Date created:		2007-08-03
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Twitter
PORTVERSION=	3.10001
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to twitter.com

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
    		${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA \
    		${SITE_PERL}/Data/Visitor/Callback.pm:${PORTSDIR}/devel/p5-Data-Visitor \
    		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
    		${SITE_PERL}/MooseX/AttributeHelpers.pm:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
    		${SITE_PERL}/MooseX/MultiInitArg.pm:${PORTSDIR}/devel/p5-MooseX-MultiInitArg \
		${SITE_PERL}/MooseX/Traits.pm:${PORTSDIR}/devel/p5-MooseX-Traits \
		${SITE_PERL}/namespace/autoclean.pm:${PORTSDIR}/devel/p5-namespace-autoclean \
		${SITE_PERL}/Net/OAuth/Simple.pm:${PORTSDIR}/net/p5-Net-OAuth-Simple \
		${SITE_PERL}/JSON/Any.pm:${PORTSDIR}/converters/p5-JSON-Any
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Twitter.3 Net::Twitter::Search.3 Net::Identica.3 \
		Net::Twitter::Error.3 Net::Twitter::Role::OAuth.3 \
		Net::Twitter::Role::API::Lists.3 \
		Net::Twitter::Role::API::REST.3 \
		Net::Twitter::Role::API::TwitterVision.3 \
		Net::Twitter::OAuth.3 Net::Twitter::Core.3 \
		Net::Twitter::API.3 Net::Twitter::Role::API::Search.3 \
		Net::Twitter::Role::InflateObjects.3 \
		Net::Twitter::Role::RateLimit.3 \
		Net::Twitter::Role::WrapError.3 \
		Net::Twitter::Role::Legacy.3

.include <bsd.port.mk>
