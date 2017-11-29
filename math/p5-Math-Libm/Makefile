# Created by: Tomoyuki Sakurai <y@trombik.org>
# $FreeBSD$

PORTNAME=	Math-Libm
PORTVERSION=	1.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	y@trombik.org
COMMENT=	Perl extension for the C math library, libm

LICENSE=	NONE

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Libm/Libm.so

.include <bsd.port.mk>
