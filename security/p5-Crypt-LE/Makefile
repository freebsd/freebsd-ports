# $FreeBSD$

PORTNAME=	Crypt-LE
PORTVERSION=	0.19
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Let's Encrypt API interfacing module

LICENSE=	ART20

RUN_DEPENDS=	p5-Crypt-PKCS10>=0:security/p5-Crypt-PKCS10 \
		p5-Crypt-OpenSSL-PKCS10>=0:security/p5-Crypt-OpenSSL-PKCS10 \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Crypt-Format>=0:security/p5-Crypt-Format

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
