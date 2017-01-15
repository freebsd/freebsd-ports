# Created by: chinsan
# $FreeBSD$

PORTNAME=	HTTP-Async
PORTVERSION=	0.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process multiple HTTP requests in parallel without blocking

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-Net-HTTPS-NB>=0.13:net/p5-Net-HTTPS-NB \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-HTTP-Server-Simple>=0:www/p5-Test-HTTP-Server-Simple \
		p5-Test-TCP>=0:devel/p5-Test-TCP

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
