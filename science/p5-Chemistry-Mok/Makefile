# New ports collection makefile for:	p5-Chemistry-Mok
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Mok
PORTVERSION=	0.25
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Molecular awk interpreter

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern

MAN1=	mok.1
MAN3=	Chemistry::Mok.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
