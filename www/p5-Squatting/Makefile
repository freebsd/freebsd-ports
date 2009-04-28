# New ports collection makefile for:	www/p5-Squatting
# Date created:				07 July 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Squatting
PORTVERSION=	0.60
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BE/BEPPU
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A Camping-inspired Web Microframework for Perl

BUILD_DEPENDS=	p5-Continuity>=0.991:${PORTSDIR}/www/p5-Continuity \
		p5-Class-C3-Componentised>0:${PORTSDIR}/devel/p5-Class-C3-Componentised \
		p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Shell-Perl>0:${PORTSDIR}/shells/p5-Shell-Perl \
		p5-JSON-XS>0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	squatting.1
MAN3=	Squatting.3 \
	Squatting::Controller.3 \
	Squatting::Cookbook.3 \
	Squatting::H.3 \
	Squatting::Mapper.3 \
	Squatting::On::Catalyst.3 \
	Squatting::On::CGI.3 \
	Squatting::On::Continuity.3 \
	Squatting::On::MP13.3 \
	Squatting::On::MP20.3 \
	Squatting::View.3 \
	Squatting::With::AccessTrace.3 \
	Squatting::With::Coro::Debug.3 \
	Squatting::With::Log.3

.include <bsd.port.mk>
