# New ports collection makefile for:	Math::Vec
# Date created:		6 May 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Vec
PORTVERSION=	0.040
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/E/EW/EWILHELM
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.04

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Object-Oriented Vector Math Methods in Perl

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes
MAN3=		Math::Vec.3

.include <bsd.port.mk>
