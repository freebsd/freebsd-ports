# New ports collection makefile for:	Math-Symbolic-Custom-Pattern
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic-Custom-Pattern
PORTVERSION=	1.11
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Pattern matching on Math::Symbolic trees

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::Pattern.3 \
	Math::Symbolic::Custom::Pattern::Export.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
