# New ports collection makefile for:	p5-Catalyst-Plugin-Browser
# Date created:		2008-12-21
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Browser
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Browser Detection for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-TraitFor-Request-BrowserDetect>=0:${PORTSDIR}/www/p5-Catalyst-TraitFor-Request-BrowserDetect
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Browser.3

.include <bsd.port.mk>
