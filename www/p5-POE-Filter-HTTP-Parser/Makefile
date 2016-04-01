# $FreeBSD$

PORTNAME=	POE-Filter-HTTP-Parser
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP POE filter for HTTP clients or servers

BUILD_DEPENDS=	p5-POE>=1.003:devel/p5-POE \
		p5-libwww>=0:www/p5-libwww \
		p5-HTTP-Parser>=0.06:www/p5-HTTP-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-POE-Client-TCP>=0:devel/p5-Test-POE-Client-TCP \
		p5-Test-POE-Server-TCP>=0:devel/p5-Test-POE-Server-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
