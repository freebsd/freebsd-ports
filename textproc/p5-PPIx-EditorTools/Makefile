# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	PPIx-EditorTools
PORTVERSION=	0.19
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SZABGAB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility methods and base class for manipulating Perl via PPI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-XSAccessor>=1.02:devel/p5-Class-XSAccessor \
		p5-PPI>=1.215:textproc/p5-PPI \
		p5-Try-Tiny>=0.11:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-NoWarnings>=0.084:devel/p5-Test-NoWarnings

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
