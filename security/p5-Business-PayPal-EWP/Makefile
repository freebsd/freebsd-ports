PORTNAME=	Business-PayPal-EWP
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for PayPal Encrypted Website Payments

RUN_DEPENDS=	p5-Net-SSLeay>=0:security/p5-Net-SSLeay
BUILD_DEPENDS=	p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		dos2unix perl5 ssl
USE_PERL5=	configure
CONFIGURE_ARGS=	${OPENSSLBASE}

.include <bsd.port.mk>
