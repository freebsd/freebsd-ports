# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CQL-Parser
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compiles CQL strings into parse trees of Node subtypes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.1:devel/p5-Class-Accessor \
		p5-Clone>=0.15:devel/p5-Clone \
		p5-String-Tokenizer>=0.05:textproc/p5-String-Tokenizer
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Changes>=0:devel/p5-CPAN-Changes \
		p5-Test-Exception>=0.21:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
