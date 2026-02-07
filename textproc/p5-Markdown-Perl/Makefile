PORTNAME=		Markdown-Perl
PORTVERSION=		1.11
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	CPAN:MATHIAS
PKGNAMEPREFIX=		p5-

MAINTAINER=		root@dc365.ru
COMMENT=		Very configurable Markdown processor
WWW=			https://metacpan.org/dist/Markdown-Perl

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker-CPANfile>=0.09:devel/p5-ExtUtils-MakeMaker-CPANfile \
		p5-Test-CPANfile>=0:devel/p5-Test-CPANfile
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-Unicode-CaseFold>=0:textproc/p5-Unicode-CaseFold \
		p5-YAML-PP>=0:textproc/p5-YAML-PP \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny

USES=			localbase perl5
USE_PERL5=		configure test

NO_ARCH=		yes

.include <bsd.port.mk>
