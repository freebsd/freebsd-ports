# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Int64
PORTVERSION=	0.54
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate 64 bits integers in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Int64/Int64.so

.include <bsd.port.mk>
