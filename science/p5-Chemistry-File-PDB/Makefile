# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Chemistry-File-PDB
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to read and write PDB files

BUILD_DEPENDS=	p5-Chemistry-Mol>=0.37:science/p5-Chemistry-Mol \
		p5-Chemistry-MacroMol>=0.06:science/p5-Chemistry-MacroMol
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
