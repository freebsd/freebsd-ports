# New ports collection makefile for:	Chemistry-File-PDB
# Date created:				17 May, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-PDB
PORTVERSION=	0.23
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl module to read and write PDB files

BUILD_DEPENDS=	p5-Chemistry-Mol>=0.37:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Chemistry-MacroMol>=0.06:${PORTSDIR}/science/p5-Chemistry-MacroMol
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Chemistry::File::PDB.3

.include <bsd.port.mk>
