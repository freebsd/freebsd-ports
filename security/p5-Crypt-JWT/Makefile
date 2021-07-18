# Created by: Sergei Vyshenski

PORTNAME=	Crypt-JWT
PORTVERSION=	0.033
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	JSON Web Token (JWT, JWS, JWE) as defined by RFC7519, RFC7515, RFC7516

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CryptX>=0.067:security/p5-CryptX \
		p5-JSON>=0:converters/p5-JSON

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
