PORTNAME=	HTTP-Tiny-Paranoid
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROBN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Safer HTTP::Tiny
WWW=		https://metacpan.org/release/HTTP-Tiny-Paranoid

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
		p5-Net-DNS-Paranoid>0:dns/p5-Net-DNS-Paranoid

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
NO_TEST=	yes

PLIST_FILES=	${SITE_MAN3_REL}/HTTP::Tiny::Paranoid.3.gz \
		${SITE_PERL_REL}/HTTP/Tiny/Paranoid.pm

.include <bsd.port.mk>
