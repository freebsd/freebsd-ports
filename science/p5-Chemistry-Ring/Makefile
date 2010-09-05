# New ports collection makefile for:	p5-Chemistry-Ring
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Ring
PORTVERSION=	0.20
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Represent a ring as a substructure of a molecule

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression

MAN3=	Chemistry::Ring.3 Chemistry::Ring::Find.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
