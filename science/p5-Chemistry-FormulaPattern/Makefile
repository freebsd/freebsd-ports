# New ports collection makefile for:	p5-Chemistry-FormulaPattern
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-FormulaPattern
PORTVERSION=	0.10
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Match molecule by formula

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern

MAN3=	Chemistry::FormulaPattern.3 Chemistry::File::FormulaPattern.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
