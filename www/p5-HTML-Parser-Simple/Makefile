PORTNAME=	HTML-Parser-Simple
PORTVERSION=	2.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse nice HTML files without needing a compiler

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=1.003001:devel/p5-Moo \
		p5-Tree-Simple>=1.22:devel/p5-Tree-Simple
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
