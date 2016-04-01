# $FreeBSD$

PORTNAME=	Email-MIME-Creator-ISO_2022_JP
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Email::MIME mixin to create an iso-2022-jp mail

RUN_DEPENDS=	\
	p5-Email-MIME>=1.900:mail/p5-Email-MIME \
	p5-Sub-Install>0:devel/p5-Sub-Install
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Classy>=0:devel/p5-Test-Classy \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
