# New ports collection makefile for:	p5-NetAddr-IP
# Date created:				12 July 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP
PORTVERSION=	3.24
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for working with IP addresses and blocks thereof

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		NetAddr::IP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later version
.endif

.include <bsd.port.post.mk>
