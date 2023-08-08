PORTNAME=	XML-Enc
PORTVERSION=	0.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML Encryption support
WWW=		https://metacpan.org/dist/XML-Enc

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-X509>=0:security/p5-Crypt-OpenSSL-X509 \
		p5-CryptX>=0.062:security/p5-CryptX \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML
TEST_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0:security/p5-Crypt-OpenSSL-Guess \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-Test-Lib>=0:devel/p5-Test-Lib \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
