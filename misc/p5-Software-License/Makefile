PORTNAME=	Software-License
PORTVERSION=	0.104002
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Packages that provide templated software licenses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Section>=0:devel/p5-Data-Section \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Text-Template>=0:textproc/p5-Text-Template
TEST_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
