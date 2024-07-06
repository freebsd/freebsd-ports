PORTNAME=	Net-SAML2
PORTVERSION=	0.80
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SAML2 bindings and protocol implementation
WWW=		https://metacpan.org/dist/Net-SAML2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-Random>=0:security/p5-Crypt-OpenSSL-Random \
		p5-Crypt-OpenSSL-Verify>=0:security/p5-Crypt-OpenSSL-Verify \
		p5-Crypt-OpenSSL-X509>=0:security/p5-Crypt-OpenSSL-X509 \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-XSD>=0:devel/p5-DateTime-Format-XSD \
		p5-DateTime-HiRes>=0:devel/p5-DateTime-HiRes \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
		p5-MooseX-Types-DateTime>=0:devel/p5-MooseX-Types-DateTime \
		p5-MooseX-Types-URI>=0:devel/p5-MooseX-Types-URI \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Types-Serialiser>=0:devel/p5-Types-Serialiser \
		p5-URI>=0:net/p5-URI \
		p5-URI-Encode>=0:www/p5-URI-Encode \
		p5-URN-OASIS-SAML2>=0.004:security/p5-URN-OASIS-SAML2 \
		p5-XML-Enc>=0.13:textproc/p5-XML-Enc \
		p5-XML-Generator>=1.13:textproc/p5-XML-Generator \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Sig>=0.64:textproc/p5-XML-Sig \
		p5-libwww>=0:www/p5-libwww \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Import-Into>=0:devel/p5-Import-Into \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Sub-Override>=0:devel/p5-Sub-Override \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Lib>=0:devel/p5-Test-Lib \
		p5-Test-Mock-One>=0:devel/p5-Test-Mock-One \
		p5-Test-NoTabs>=0:devel/p5-Test-NoTabs \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
