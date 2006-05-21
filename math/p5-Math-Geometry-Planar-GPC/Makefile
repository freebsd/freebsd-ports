# New ports collection makefile for:	Math-Geometry-Planar-GPC
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Geometry-Planar-GPC
PORTVERSION=	1.04
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl wrapper for Alan Murta's gpc library

MAN3=	Math::Geometry::Planar::GPC.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

#.if ${PERL_LEVEL} < 500600
#IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
#.endif

.include <bsd.port.post.mk>
