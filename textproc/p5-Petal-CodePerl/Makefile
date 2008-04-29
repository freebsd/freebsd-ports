# New ports collection makefile for:	p5-Petal-CodePerl
# Date created:				26 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Petal-CodePerl
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FD/FDALY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make Petal go faster by compiling the expressions

BUILD_DEPENDS=	${SITE_PERL}/Petal.pm:${PORTSDIR}/textproc/p5-Petal \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Code/Perl.pm:${PORTSDIR}/devel/p5-Code-Perl
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Petal::CodePerl.3 Petal::CodePerl::Expr.3 \
	Petal::CodePerl::Modifiers.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
