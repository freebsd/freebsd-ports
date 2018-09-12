# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Email-Valid
PORTVERSION=	1.202
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check validity of Internet email addresses

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Net-DNS>0:dns/p5-Net-DNS \
		p5-Net-Domain-TLD>=1.65:dns/p5-Net-Domain-TLD

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
