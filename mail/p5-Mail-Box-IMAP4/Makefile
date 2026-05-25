PORTNAME=	Mail-Box-IMAP4
PORTVERSION=	4.01
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handle IMAP4 folders as client
WWW=		https://metacpan.org/release/Mail-Box-IMAP4

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-Mail-Box>=4.0:mail/p5-Mail-Box \
		p5-Mail-IMAPClient>=3.42:mail/p5-Mail-IMAPClient \
		p5-Mail-Message>=4.0:mail/p5-Mail-Message \
		p5-Mail-Transport>=4.0:mail/p5-Mail-Transport

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
