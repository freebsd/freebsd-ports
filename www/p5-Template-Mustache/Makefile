PORTNAME=	Template-Mustache
DISTVERSION=	1.4.0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Perl version of the fabulous Mustache template language
WWW=		https://metacpan.org/release/Template-Mustache

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Escape-Houdini>=0:devel/p5-Escape-Houdini \
		p5-List-AllUtils>=0:devel/p5-List-AllUtils \
		p5-Moo>0:devel/p5-Moo \
		p5-MooseX-MungeHas>0:devel/p5-MooseX-MungeHas \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-YAML-Syck>=1.15:textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Requires>0:devel/p5-Test-Requires \
		p5-Test-Simple>0:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
