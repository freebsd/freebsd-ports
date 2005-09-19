# New ports collection makefile for:	AI-Perceptron
# Date created:				04 Nov 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	AI-Perceptron
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	AI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for introducing to internal operations of neural networks

BUILD_DEPENDS=	${SITE_PERL}/accessors.pm:${PORTSDIR}/devel/p5-accessors
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		AI::Perceptron.3

.include <bsd.port.pre.mk>

# p5-accessors requires 5.6.0
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or above
.endif

.include <bsd.port.post.mk>
