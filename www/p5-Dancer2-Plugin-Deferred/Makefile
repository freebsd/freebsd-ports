# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Deferred
PORTVERSION=	0.007017
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dancer2 plugin to defer messages or data across redirections

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Plack>=0:www/p5-Plack

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
