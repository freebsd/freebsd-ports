# New ports collection makefile for:	www/p5-Catalyst-View-TT
# Date created:				04 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-TT
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Template Toolkit view class for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Template/Timer.pm:${PORTSDIR}/www/p5-Template-Timer \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Helper::View::TT.3 \
	Catalyst::Helper::View::TTSite.3 \
	Catalyst::View::TT.3

.include <bsd.port.mk>
