# New ports collection makefile for:	HTML::Template::Pluggable
# Date created:				21 March 2006
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-Pluggable
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Extends HTML::Template with plugin support

BUILD_DEPENDS=	p5-HTML-Template>=2.7:${PORTSDIR}/www/p5-HTML-Template \
		p5-Test-MockObject>=1:${PORTSDIR}/devel/p5-Test-MockObject \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.6+

MAN3=		HTML::Template::Pluggable.3 \
		HTML::Template::Plugin::Dot.3

.include <bsd.port.mk>
