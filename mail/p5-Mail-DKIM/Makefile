PORTNAME=	Mail-DKIM
PORTVERSION=	1.20240827
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 module to process and/or create DKIM email
WWW=		https://metacpan.org/dist/Mail-DKIM

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-CryptX>=0:security/p5-CryptX \
		p5-Mail-AuthenticationResults>=0:mail/p5-Mail-AuthenticationResults \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Net-DNS>=0:dns/p5-Net-DNS
TEST_DEPENDS=	p5-Net-DNS-Resolver-Mock>=0:dns/p5-Net-DNS-Resolver-Mock \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	scripts/*.pl

NO_ARCH=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dkim*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
