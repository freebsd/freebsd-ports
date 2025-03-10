PORTNAME=	Net-SSL-ExpireDate
PORTVERSION=	1.25
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Obtain expiration date of certificate
WWW=		https://metacpan.org/release/Net-SSL-ExpireDate

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Crypt-OpenSSL-X509>=0:security/p5-Crypt-OpenSSL-X509 \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Time-Duration-Parse>=0:devel/p5-Time-Duration-Parse \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
