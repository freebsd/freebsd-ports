# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	HTTP-XSCookies
PORTVERSION=	0.000021
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast XS cookie mangling for Perl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTTP/XSCookies/XSCookies.so

.include <bsd.port.mk>
