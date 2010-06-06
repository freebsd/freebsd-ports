# New ports collection makefile for:	p5-Net-Google-DataAPI
# Date created:				23 March 2010
# Whom:					Gunter Wambaugh <gunter@six-two.net>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-DataAPI
PORTVERSION=	0.18
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gunter@six-two.net
COMMENT=	Base implementations for modules to negotiate with Google Data APIs

BUILD_DEPENDS=	${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Any/Moose.pm:${PORTSDIR}/devel/p5-Any-Moose \
		${SITE_PERL}/Net/Google/AuthSub.pm:${PORTSDIR}/net/p5-Net-Google-AuthSub \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/Net/OAuth.pm:${PORTSDIR}/net/p5-Net-OAuth \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Lingua/EN/Inflect/Number.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		${SITE_PERL}/namespace/autoclean.pm:${PORTSDIR}/devel/p5-namespace-autoclean \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Test/MockModule.pm:${PORTSDIR}/devel/p5-Test-MockModule \
		${SITE_PERL}/Test/MockObject.pm:${PORTSDIR}/devel/p5-Test-MockObject \
		${SITE_PERL}/UNIVERSAL/isa.pm:${PORTSDIR}/devel/p5-UNIVERSAL-isa \
		${SITE_PERL}/UNIVERSAL/can.pm:${PORTSDIR}/devel/p5-UNIVERSAL-can
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Google::DataAPI.3 \
		Net::Google::DataAPI::Auth::ClientLogin::Multiple.3 \
		Net::Google::DataAPI::Auth::OAuth.3 \
		Net::Google::DataAPI::Role::Entry.3 \
		Net::Google::DataAPI::Role::HasContent.3 \
		Net::Google::DataAPI::Role::Service.3

.include <bsd.port.mk>
