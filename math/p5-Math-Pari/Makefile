# New ports collection makefile for:	p5-Math-Pari
# Date created:				Tue Sep 11 02:08:49 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Pari
PORTVERSION=	2.010201
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org

BUILD_DEPENDS=	pari:${PORTSDIR}/math/pari:configure

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Math::Pari.3 Math::libPARI.3

.include <bsd.port.mk>
