PORTNAME=	Dancer-Plugin-REST
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YANICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dancer plugin for writing RESTful apps
WWW=		https://metacpan.org/release/Dancer-Plugin-REST

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer>=1.3111:www/p5-Dancer
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
