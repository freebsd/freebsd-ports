# New ports collection makefile for:	p5-Chemistry-File-SMARTS
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-SMARTS
PORTVERSION=	0.22
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	SMARTS chemical substructure pattern linear notation parser

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES

MAN3=	Chemistry::File::SMARTS.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
