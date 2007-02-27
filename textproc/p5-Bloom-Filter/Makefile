# New ports collection makefile for: 	p5-Bloom-Filter
# Date created: 		     	August 06, 2004
# Whom:					Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Bloom-Filter
PORTVERSION=	1.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MC/MCEGLOWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A probabilistic algorithm for doing existence tests

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bloom::Filter.3

.include <bsd.port.mk>
