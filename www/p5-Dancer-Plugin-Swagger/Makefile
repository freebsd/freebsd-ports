PORTNAME=	Dancer-Plugin-Swagger
PORTVERSION=	0.2.0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Dancer plugin to create Swagger documentation for app REST

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Clone>=0:devel/p5-Clone \
		p5-File-ShareDir-Install>=0:devel/p5-File-ShareDir-Install \
		p5-File-ShareDir-Tarball>=0:devel/p5-File-ShareDir-Tarball \
		p5-List-AllUtils>=0:devel/p5-List-AllUtils \
		p5-Moo>=0:devel/p5-Moo \
		p5-MooseX-MungeHas>=0:devel/p5-MooseX-MungeHas \
		p5-MooX-Singleton>=0:devel/p5-MooX-Singleton \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-PerlX-Maybe>=0:devel/p5-PerlX-Maybe \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Dancer>=0:www/p5-Dancer \
		p5-Dancer-Plugin-REST>=0:www/p5-Dancer-Plugin-REST
TEST_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-WWW-Mechanize-PSGI>=0:devel/p5-Test-WWW-Mechanize-PSGI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
