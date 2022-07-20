PORTNAME=	CSS-Packer
PORTVERSION=	2.08
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another CSS minifier

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Regexp-RegGrp>=1.001001:devel/p5-Regexp-RegGrp
TEST_DEPENDS=	p5-Test-File-Contents>=0.21:devel/p5-Test-File-Contents \
		p5-Test-Pod>=1.22:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
