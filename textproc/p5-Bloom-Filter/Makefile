# New ports collection makefile for: 	p5-Bloom-Filter
# Date created: 		     	August 06, 2004
# Whom:					Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

# Bloom::Filter.pm is not part of the standard
# MASTER_SITES tree due to unresolved namespace
# issues

PORTNAME=	Bloom-Filter
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.cpan.org/authors/id/M/MC/MCEGLOWS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	A probabilistic algorithm for doing existence tests

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bloom::Filter.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"requires Perl 5.6 or above"
.endif

.include <bsd.port.post.mk>
