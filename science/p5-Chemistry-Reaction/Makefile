# New ports collection makefile for:	p5-Chemistry-Reaction
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Reaction
PORTVERSION=	0.02
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Represent a ring as a substructure of a molecule 

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern

MAN3=	Chemistry::Reaction.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
