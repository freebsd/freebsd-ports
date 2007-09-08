# New ports collection makefile for:	net/p5-Geo-IPfree
# Date created:				02 April 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-IPfree
PORTVERSION=	0.2
CATEGORIES=	net perl5 geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Look up country from an IP Address

BUILD_DEPENDS=	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geo::IPfree.3

.include <bsd.port.mk>
