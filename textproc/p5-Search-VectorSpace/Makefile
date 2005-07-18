# New ports collection makefile for:	p5-Search-VectorSpace
# Date created:		2004-10-26
# Whom:			clsung
#
# $FreeBSD$
#

PORTNAME=	Search-VectorSpace
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A very basic vector-space search engine perl module

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PDL.pm:${PORTSDIR}/math/PDL \
		${SITE_PERL}/Lingua/Stem.pm:${PORTSDIR}/textproc/p5-Lingua-Stem
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Search::VectorSpace.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
