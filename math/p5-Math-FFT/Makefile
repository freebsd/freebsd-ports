# Created by: Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-FFT
PORTVERSION=	1.34
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module providing an interface to Fast Fourier Transform routines

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/FFT/FFT.so
.include <bsd.port.mk>
