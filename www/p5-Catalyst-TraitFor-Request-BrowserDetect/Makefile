# New ports collection makefile for:	p5-Catalyst-TraitFor-Request-BrowserDetect
# Date created:							January 31, 2010
# Whom:									Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-TraitFor-Request-BrowserDetect
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Browser detection for Catalyst::Requests

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-CatalystX-RoleApplicator>=0:${PORTSDIR}/www/p5-CatalystX-RoleApplicator \
	p5-HTTP-BrowserDetect>=0:${PORTSDIR}/www/p5-HTTP-BrowserDetect

PERL_CONFIGURE=	yes

MAN3=	Catalyst::TraitFor::Request::BrowserDetect.3

.include <bsd.port.mk>
