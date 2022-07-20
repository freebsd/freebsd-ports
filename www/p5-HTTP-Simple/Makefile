PORTNAME=	HTTP-Simple
PORTVERSION=	0.004
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple procedural interface to HTTP::Tiny

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cpanel-JSON-XS>=4.11:converters/p5-Cpanel-JSON-XS \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
