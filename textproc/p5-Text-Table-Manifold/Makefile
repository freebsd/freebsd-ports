PORTNAME=	Text-Table-Manifold
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Render tables in manifold formats

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Const-Exporter>=0.2.3:devel/p5-Const-Exporter \
		p5-HTML-Entities-Interpolate>=1.05:textproc/p5-HTML-Entities-Interpolate \
		p5-List-AllUtils>=0.08:devel/p5-List-AllUtils \
		p5-Module-Runtime>=0.014:devel/p5-Module-Runtime \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-String-TtyLength>=0.02:textproc/p5-String-TtyLength \
		p5-Type-Tiny>=1.000004:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Pod>=1.48:devel/p5-Test-Pod

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
