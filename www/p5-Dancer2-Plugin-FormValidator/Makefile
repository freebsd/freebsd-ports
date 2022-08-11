PORTNAME=	Dancer2-Plugin-FormValidator
PORTVERSION=	1.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Neat and easy to start form validation plugin for Dancer2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-Dancer2-Plugin-Deferred>=0:www/p5-Dancer2-Plugin-Deferred \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-Moo>=0:devel/p5-Moo \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-utf8-all>=0:textproc/p5-utf8-all
TEST_DEPENDS=	p5-Data-FormValidator>=0:textproc/p5-Data-FormValidator \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
