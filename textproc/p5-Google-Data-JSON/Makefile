# Created by: chinsan
# $FreeBSD$

PORTNAME=	Google-Data-JSON
PORTVERSION=	0.1.10
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TAKERU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	General XML-JSON converter based on Google Data APIs

BUILD_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-JSON-Any>=0:converters/p5-JSON-Any \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Perl6-Export-Attrs>=0:devel/p5-Perl6-Export-Attrs \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-XML-Atom>=0:textproc/p5-XML-Atom \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
