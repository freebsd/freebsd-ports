# $FreeBSD$

PORTNAME=	Crypt-RSA-Parse
PORTVERSION=	0.044
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Parse RSA keys

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Accessor>=0.34:devel/p5-Class-Accessor \
		p5-Convert-ASN1>=0.27:converters/p5-Convert-ASN1 \
		p5-Crypt-Format>=0.06:security/p5-Crypt-Format
TEST_DEPENDS=	p5-Test-NoWarnings>=0.01:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
