# New ports collection makefile for:	p5-Math-Algebra-Symbols
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Algebra-Symbols
PORTVERSION=	1.21
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Symbolic Algebra in Pure Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Algebra::Symbols.3 \
	Math::Algebra::Symbols::Sum.3 \
	Math::Algebra::Symbols::Symbols.3 \
	Math::Algebra::Symbols::Term.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	currently requires Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
