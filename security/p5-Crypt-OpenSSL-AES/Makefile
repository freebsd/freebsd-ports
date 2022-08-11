PORTNAME=	Crypt-OpenSSL-AES
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jdferrell3@yahoo.com
COMMENT=	Perl wrapper around OpenSSL's AES library

USES=		perl5 ssl
USE_PERL5=	configure
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.mk>
