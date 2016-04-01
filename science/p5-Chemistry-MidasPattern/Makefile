# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Chemistry-MidasPattern
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Select atoms in macromolecules

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:science/p5-Chemistry-Mol \
		p5-Chemistry-File-PDB>=0:science/p5-Chemistry-File-PDB \
		p5-Chemistry-MacroMol>=0:science/p5-Chemistry-MacroMol \
		p5-Chemistry-Pattern>=0:science/p5-Chemistry-Pattern
RUN_DEPENDS=	p5-Chemistry-Mol>=0:science/p5-Chemistry-Mol \
		p5-Chemistry-File-PDB>=0:science/p5-Chemistry-File-PDB \
		p5-Chemistry-MacroMol>=0:science/p5-Chemistry-MacroMol \
		p5-Chemistry-Pattern>=0:science/p5-Chemistry-Pattern

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
