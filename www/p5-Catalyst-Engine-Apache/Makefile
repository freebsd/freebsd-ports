# New ports collection makefile for:	p5-Catalyst-Engine-Apache
# Date created:		15 Nov 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Engine-Apache
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AG/AGRUNDMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Catalyst Apache Engines

BUILD_DEPENDS=	p5-Catalyst>=5.50:${PORTSDIR}/www/p5-Catalyst
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Catalyst::Engine::Apache.3 \
		Catalyst::Engine::Apache2::MP19.3 \
		Catalyst::Engine::Apache2::MP20.3 \
		Catalyst::Engine::Apache::MP13.3 \
		Catalyst::Engine::Apache2.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
