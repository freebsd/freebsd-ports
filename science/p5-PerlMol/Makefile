# New ports collection makefile for:	p5-PerlMol
# Date created:		2010-03-04
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	PerlMol
PORTVERSION=	0.3500
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl modules for molecular chemistry

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/MacroMol.pm:${PORTSDIR}/science/p5-Chemistry-MacroMol \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/File/SMARTS.pm:${PORTSDIR}/science/p5-Chemistry-File-SMARTS \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Isotope.pm:${PORTSDIR}/science/p5-Chemistry-Isotope \
		${SITE_PERL}/Chemistry/3DBuilder.pm:${PORTSDIR}/science/p5-Chemistry-3DBuilder \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/File/PDB.pm:${PORTSDIR}/science/p5-Chemistry-File-PDB \
		${SITE_PERL}/Chemistry/File/XYZ.pm:${PORTSDIR}/science/p5-Chemistry-File-XYZ \
		${SITE_PERL}/Chemistry/File/VRML.pm:${PORTSDIR}/science/p5-Chemistry-File-VRML \
		${SITE_PERL}/Chemistry/File/SLN.pm:${PORTSDIR}/science/p5-Chemistry-File-SLN \
		${SITE_PERL}/Chemistry/File/Mopac.pm:${PORTSDIR}/science/p5-Chemistry-File-Mopac \
		${SITE_PERL}/Chemistry/File/MDLMol.pm:${PORTSDIR}/science/p5-Chemistry-File-MDLMol \
		${SITE_PERL}/Chemistry/Reaction.pm:${PORTSDIR}/science/p5-Chemistry-Reaction \
		${SITE_PERL}/Chemistry/FormulaPattern.pm:${PORTSDIR}/science/p5-Chemistry-FormulaPattern \
		${SITE_PERL}/Chemistry/MidasPattern.pm:${PORTSDIR}/science/p5-Chemistry-MidasPattern \
		${SITE_PERL}/Chemistry/Mok.pm:${PORTSDIR}/science/p5-Chemistry-Mok \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression
BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/MacroMol.pm:${PORTSDIR}/science/p5-Chemistry-MacroMol \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/File/SMARTS.pm:${PORTSDIR}/science/p5-Chemistry-File-SMARTS \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords \
		${SITE_PERL}/Chemistry/Pattern.pm:${PORTSDIR}/science/p5-Chemistry-Pattern \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Isotope.pm:${PORTSDIR}/science/p5-Chemistry-Isotope \
		${SITE_PERL}/Chemistry/3DBuilder.pm:${PORTSDIR}/science/p5-Chemistry-3DBuilder \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/File/PDB.pm:${PORTSDIR}/science/p5-Chemistry-File-PDB \
		${SITE_PERL}/Chemistry/File/XYZ.pm:${PORTSDIR}/science/p5-Chemistry-File-XYZ \
		${SITE_PERL}/Chemistry/File/VRML.pm:${PORTSDIR}/science/p5-Chemistry-File-VRML \
		${SITE_PERL}/Chemistry/File/SLN.pm:${PORTSDIR}/science/p5-Chemistry-File-SLN \
		${SITE_PERL}/Chemistry/File/Mopac.pm:${PORTSDIR}/science/p5-Chemistry-File-Mopac \
		${SITE_PERL}/Chemistry/File/MDLMol.pm:${PORTSDIR}/science/p5-Chemistry-File-MDLMol \
		${SITE_PERL}/Chemistry/Reaction.pm:${PORTSDIR}/science/p5-Chemistry-Reaction \
		${SITE_PERL}/Chemistry/FormulaPattern.pm:${PORTSDIR}/science/p5-Chemistry-FormulaPattern \
		${SITE_PERL}/Chemistry/MidasPattern.pm:${PORTSDIR}/science/p5-Chemistry-MidasPattern \
		${SITE_PERL}/Chemistry/Mok.pm:${PORTSDIR}/science/p5-Chemistry-Mok \
		${SITE_PERL}/Statistics/Regression.pm:${PORTSDIR}/math/p5-Statistics-Regression

PERL_CONFIGURE=	yes

MAN3=	PerlMol.3

.include <bsd.port.mk>
