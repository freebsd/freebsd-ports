# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	HTTP-Tiny-UA
PORTVERSION=	0.006
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Higher-level UA features for HTTP::Tiny

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Tiny>=1.000:devel/p5-Class-Tiny \
		p5-superclass>=0:devel/p5-superclass

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
