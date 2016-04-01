# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Email-Valid
PORTVERSION=	1.192
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Check validity of Internet email addresses

COMMON_DEPENDS=	p5-Net-DNS>0:dns/p5-Net-DNS \
		p5-Mail-Tools>0:mail/p5-Mail-Tools \
		p5-Net-Domain-TLD>0:dns/p5-Net-Domain-TLD
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
