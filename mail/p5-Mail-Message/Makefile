PORTNAME=	Mail-Message
PORTVERSION=	4.01
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General message object
WWW=		https://metacpan.org/release/Mail-Message

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-MIME-Types>=1.004:mail/p5-MIME-Types \
		p5-Mail-Tools>=2.17:mail/p5-Mail-Tools \
		p5-String-Print>=1.01:textproc/p5-String-Print \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=1.23:net/p5-URI \
		p5-User-Identity>=4.0:devel/p5-User-Identity

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
