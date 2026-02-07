PORTNAME=	Catalyst-Authentication-Credential-HTTP
PORTVERSION=	1.019
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP plain and digest authentication plugin for Catalyst
WWW=		https://metacpan.org/release/Catalyst-Authentication-Credential-HTTP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0.10005:www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Runtime>0:www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Crypt-SysRandom>0:security/p5-Crypt-SysRandom \
		p5-Data-UUID>=0.11:devel/p5-Data-UUID \
		p5-String-Escape>0:textproc/p5-String-Escape \
		p5-URI>0:net/p5-URI
TEST_DEPENDS=	p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-MockObject>0:devel/p5-Test-MockObject \
		p5-Test-Needs>0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	YES

.include <bsd.port.mk>
