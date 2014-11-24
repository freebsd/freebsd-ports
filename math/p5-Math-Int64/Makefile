# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Int64
PORTVERSION=	0.34
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
	${CHMOD} u+w ${STAGEDIR}${SITE_ARCH}/auto/Math/Int64/Int64.so
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/Math/Int64/Int64.so
	${CHMOD} u-w ${STAGEDIR}${SITE_ARCH}/auto/Math/Int64/Int64.so

.include <bsd.port.mk>
