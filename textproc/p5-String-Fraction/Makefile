# New ports collection makefile for:	String-Fraction
# Date created:				16 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Fraction
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Convert fractions into unicode chars

BUILD_DEPENDS=	${SITE_PERL}/HTML/Fraction.pm:${PORTSDIR}/textproc/p5-HTML-Fraction
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	String::Fraction.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
