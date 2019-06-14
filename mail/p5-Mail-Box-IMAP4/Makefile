# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Box-IMAP4
PORTVERSION=	3.007
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handle IMAP4 folders as client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Mail-Box>=3.007:mail/p5-Mail-Box \
		p5-Mail-IMAPClient>=3.42:mail/p5-Mail-IMAPClient \
		p5-Mail-Message>=3:mail/p5-Mail-Message \
		p5-Mail-Transport>=3.004:mail/p5-Mail-Transport

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
