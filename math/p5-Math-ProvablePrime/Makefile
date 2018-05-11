# $FreeBSD$

PORTNAME=	Math-ProvablePrime
PORTVERSION=	0.043
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Generate a provable prime number, in pure Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/Math/ProvablePrime.pm \
		${SITE_PERL_REL}/Math/ProvablePrime/Rand.pm \
		${SITE_MAN3_REL}/Math::ProvablePrime.3.gz

pre-install:
		${RM} ${WRKSRC}/blib/lib/Math/README.pod

.include <bsd.port.mk>
