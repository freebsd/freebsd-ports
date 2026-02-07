PORTNAME=	Mail-IMAPTalk
PORTVERSION=	4.07
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IMAP client interface with lots of features
WWW=		https://metacpan.org/release/Mail-IMAPTalk

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Encode-IMAPUTF7>=0:converters/p5-Encode-IMAPUTF7

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
