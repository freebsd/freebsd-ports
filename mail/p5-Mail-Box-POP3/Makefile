PORTNAME=	Mail-Box-POP3
PORTVERSION=	4.02
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handle POP3 folders as client
WWW=		https://metacpan.org/release/Mail-Box-POP3

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-Mail-Box>=4.02:mail/p5-Mail-Box \
		p5-Mail-Transport>=4.01:mail/p5-Mail-Transport

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
