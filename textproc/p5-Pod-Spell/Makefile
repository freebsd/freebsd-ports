# $FreeBSD$

PORTNAME=	Pod-Spell
PORTVERSION=	1.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Formatter for spellchecking Pod

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Pod-Escapes>=1.01:textproc/p5-Pod-Escapes
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
