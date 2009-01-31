# New ports collection makefile for:   Business-Hours
# Date created:    23 August 2008
# Whom:            Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	Business-Hours
PORTVERSION=	0.09
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Calculate business hours during a time period

BUILD_DEPENDS=	${SITE_PERL}/Set/IntSpan.pm:${PORTSDIR}/math/p5-Set-IntSpan
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::Hours.3

.include <bsd.port.mk>
