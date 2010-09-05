# New ports collection makefile for:	p5-Chemistry-MidasPattern
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-MidasPattern
PORTVERSION=	0.11
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Select atoms in macromolecules

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/PDB.pm:${PORTSDIR}/science/p5-Chemistry-File-PDB \
		${SITE_PERL}/Chemistry/MacroMol.pm:${PORTSDIR}/science/p5-Chemistry-MacroMol \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/PDB.pm:${PORTSDIR}/science/p5-Chemistry-File-PDB \
		${SITE_PERL}/Chemistry/MacroMol.pm:${PORTSDIR}/science/p5-Chemistry-MacroMol \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern

MAN3=	Chemistry::MidasPattern.3 Chemistry::File::MidasPattern.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
