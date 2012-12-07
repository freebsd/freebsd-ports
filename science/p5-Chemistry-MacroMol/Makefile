# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Chemistry-MacroMol
PORTVERSION=	0.06
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl toolkit to describe macromolecules

BUILD_DEPENDS=	p5-Chemistry-Mol>=0.37:${PORTSDIR}/science/p5-Chemistry-Mol
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Chemistry::MacroMol.3 Chemistry::Domain.3

.include <bsd.port.mk>
