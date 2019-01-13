# $FreeBSD$

PORTNAME=	Dancer-Plugin-CORS
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZURBORG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dancer plugin for using cross origin resource sharing

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer>=0:www/p5-Dancer \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Module-Signature>=0:security/p5-Module-Signature \
		p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
