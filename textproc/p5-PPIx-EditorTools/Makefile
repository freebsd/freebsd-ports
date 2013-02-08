# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	PPIx-EditorTools
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SZABGAB
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Utility methods and base class for manipulating Perl via PPI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-XSAccessor>=1.02:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-PPI>=1.215:${PORTSDIR}/textproc/p5-PPI \
		p5-Try-Tiny>=0.11:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Most>=0.88:${PORTSDIR}/devel/p5-Test-Most

PERL_CONFIGURE=	yes

MAN3=	PPIx::EditorTools.3 \
	PPIx::EditorTools::FindUnmatchedBrace.3 \
	PPIx::EditorTools::FindVariableDeclaration.3 \
	PPIx::EditorTools::IntroduceTemporaryVariable.3 \
	PPIx::EditorTools::Lexer.3 \
	PPIx::EditorTools::Outline.3 \
	PPIx::EditorTools::RenamePackage.3 \
	PPIx::EditorTools::RenamePackageFromPath.3 \
	PPIx::EditorTools::RenameVariable.3 \
	PPIx::EditorTools::ReturnObject.3

.include <bsd.port.mk>
