# New ports collection makefile for:	WebService-Prowl
# Date created:				18 Apr 2012
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	WebService-Prowl
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl interface to Prowl Public API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/LWP/Protocol/https.pm:${PORTSDIR}/www/p5-LWP-Protocol-https \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WebService::Prowl.3 WebService::Prowl::AnyEventHTTP.3

.include <bsd.port.mk>
