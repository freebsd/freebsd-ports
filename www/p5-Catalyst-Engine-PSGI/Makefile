# New ports collection makefile for:	Catalyst::Engine::PSGI
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Engine-PSGI
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI engine for Catalyst

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>=5.80007:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-Action-RenderView>0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Controller::Metal.3 \
	Catalyst::Engine::PSGI.3 \
	Catalyst::Helper::PSGI.3 \
	Plack::Test::Adopt::Catalyst.3

.include <bsd.port.mk>
