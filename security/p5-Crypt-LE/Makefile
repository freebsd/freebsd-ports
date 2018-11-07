# $FreeBSD$

PORTNAME=	Crypt-LE
PORTVERSION=	0.32
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Let's Encrypt API interfacing module

LICENSE=	ART20

RUN_DEPENDS=	p5-Convert-ASN1>=0:converters/p5-Convert-ASN1 \
		p5-Crypt-Format>=0:security/p5-Crypt-Format \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
