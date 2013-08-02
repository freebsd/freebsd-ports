# Ports collection makefile for: p5-Catalyst-Log-Handler
# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Log-Handler
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst log handler

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
  				p5-Log-Handler>=0:${PORTSDIR}/devel/p5-Log-Handler \
  				p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Catalyst::Plugin::Log::Handler.3

PLIST_FILES=	%%SITE_PERL%%/Catalyst/Plugin/Log/Handler.pm
PLIST_DIRS=		%%SITE_PERL%%/Catalyst/Plugin/Log \
				%%SITE_PERL%%/Catalyst/Plugin \
				%%SITE_PERL%%/Catalyst

.include <bsd.port.mk>
