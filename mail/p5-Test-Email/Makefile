PORTNAME=	Test-Email
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAMES
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Test Email Contents

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mail-POP3Client>=2:mail/p5-Mail-POP3Client \
		p5-Mail-Sendmail>=0.79:mail/p5-Mail-Sendmail \
		p5-MIME-Tools>=5.4:mail/p5-MIME-Tools \
		p5-Test-Simple>=0.7:devel/p5-Test-Simple

NO_ARCH=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
