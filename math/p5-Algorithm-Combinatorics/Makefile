# New ports collection makefile for:	Algorithm-Combinatorics
# Date created:				05 Nov 2005
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Combinatorics
PORTVERSION=	0.15
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Efficient generation of combinatorial sequences

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Algorithm::Combinatorics.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or above
.endif

.include <bsd.port.post.mk>
