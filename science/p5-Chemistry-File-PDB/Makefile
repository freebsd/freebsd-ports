# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Chemistry-File-PDB
PORTVERSION=	0.23
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl module to read and write PDB files

BUILD_DEPENDS=	p5-Chemistry-Mol>=0.37:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-MacroMol>=0.06:${PORTSDIR}/science/p5-Chemistry-MacroMol
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Chemistry::File::PDB.3

.include <bsd.port.mk>
