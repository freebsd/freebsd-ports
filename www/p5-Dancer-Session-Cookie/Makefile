# $FreeBSD$

PORTNAME=	Dancer-Session-Cookie
PORTVERSION=	0.27
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encrypted cookie-based session backend for Dancer

RUN_DEPENDS=	\
	p5-Crypt-CBC>0:security/p5-Crypt-CBC \
	p5-Crypt-Rijndael>0:security/p5-Crypt-Rijndael \
	p5-Dancer>=1.3113:www/p5-Dancer \
	p5-HTTP-Date>0:www/p5-HTTP-Date \
	p5-Session-Storage-Secure>=0.007:www/p5-Session-Storage-Secure \
	p5-String-CRC32>0:devel/p5-String-CRC32 \
	p5-Time-Duration-Parse>0:devel/p5-Time-Duration-Parse
TEST_DEPENDS=	\
	p5-Test-Exception>0:devel/p5-Test-Exception \
	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings \
	p5-Test-TCP>0:devel/p5-Test-TCP
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
