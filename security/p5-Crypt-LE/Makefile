# $FreeBSD$

PORTNAME=	Crypt-LE
PORTVERSION=	0.36
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Let's Encrypt API interfacing module

LICENSE=	ART20

RUN_DEPENDS=	p5-Convert-ASN1>=0.2:converters/p5-Convert-ASN1 \
		p5-Crypt-OpenSSL-RSA>=0.28:security/p5-Crypt-OpenSSL-RSA \
		p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=1.003005:converters/p5-JSON-MaybeXS \
		p5-Log-Log4perl>=1.27:devel/p5-Log-Log4perl \
		p5-Net-SSLeay>=1.55:security/p5-Net-SSLeay

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
