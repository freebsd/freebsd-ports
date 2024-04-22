PORTNAME=	Mail-BIMI
PORTVERSION=	3.20240205
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	BIMI (Brand Indicators for Message Identification) object
WWW=		https://metacpan.org/release/Mail-BIMI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-App-Cmd>0:devel/p5-App-Cmd \
		p5-Cache-FastMmap>0:devel/p5-Cache-FastMmap \
		p5-Convert-ASN1>0:converters/p5-Convert-ASN1 \
		p5-Crypt-OpenSSL-Verify>0:security/p5-Crypt-OpenSSL-Verify \
		p5-Crypt-OpenSSL-X509>0:security/p5-Crypt-OpenSSL-X509 \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-HTTP-Tiny-Paranoid>0:www/p5-HTTP-Tiny-Paranoid \
		p5-Import-Into>0:devel/p5-Import-Into \
		p5-JSON>0:converters/p5-JSON \
		p5-Mail-AuthenticationResults>0:mail/p5-Mail-AuthenticationResults \
		p5-Mail-DMARC>=0:mail/p5-Mail-DMARC \
		p5-Moose>0:devel/p5-Moose \
		p5-Mozilla-CA>0:www/p5-Mozilla-CA \
		p5-Net-DNS>=1.01:dns/p5-Net-DNS \
		p5-Sereal>0:converters/p5-Sereal \
		p5-Sub-Install>0:devel/p5-Sub-Install \
		p5-Term-ANSIColor>0:devel/p5-Term-ANSIColor \
		p5-XML-LibXML>2.0202:textproc/p5-XML-LibXML
TEST_DEPENDS=	p5-Test-Differences>0:devel/p5-Test-Differences \
		p5-Test-RequiresInternet>0:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	configure

TEST_ENV=	AUTHOR_TESTING=1

NO_ARCH=	yes

.include <bsd.port.mk>
