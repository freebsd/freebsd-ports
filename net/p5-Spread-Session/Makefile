# New ports collection makefile for:	p5-Spread-Session
# Date created:				May 24th 2002
# Whom:	      				Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	Spread-Session
PORTVERSION=	0.4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JM/JMAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl OO wrapper for Spread messaging toolkit

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Spread.pm:${PORTSDIR}/net/spread
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Spread::Session.3

.include <bsd.port.mk>
