PORTNAME=	Text-Hogan
PORTVERSION=	2.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mustache templating engine statement-for-statement cloned from hogan.js
WWW=		https://metacpan.org/release/Text-Hogan

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0.50:devel/p5-Clone \
		p5-HTML-Escape>=1.11:www/p5-HTML-Escape \
		p5-Ref-Util>=0.204:devel/p5-Ref-Util \
		p5-Text-Trim>=1.02:textproc/p5-Text-Trim
TEST_DEPENDS=	p5-Data-Visitor>=0.30:devel/p5-Data-Visitor \
		p5-Path-Tiny>=0.059:devel/p5-Path-Tiny \
		p5-Try-Tiny>=0.22:lang/p5-Try-Tiny \
		p5-YAML-LibYAML>=0.67:textproc/p5-YAML-LibYAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
