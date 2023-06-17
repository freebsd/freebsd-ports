PORTNAME=	XML-Generator
DISTVERSION=	1.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Perl module for generating XML documents
WWW=		https://metacpan.org/release/XML-Generator

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-DOM>=1.46:textproc/p5-XML-DOM
RUN_DEPENDS=	p5-XML-DOM>=1.46:textproc/p5-XML-DOM
TEST_DEPENDS=	p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
