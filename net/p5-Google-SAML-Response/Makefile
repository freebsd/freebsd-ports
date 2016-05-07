# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Google-SAML-Response
PORTVERSION=	0.14
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SAML responses for Google SSO implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-DSA>=0:security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Google-SAML-Request>=0:net/p5-Google-SAML-Request \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-XML-CanonicalizeXML>=0:textproc/p5-XML-CanonicalizeXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
