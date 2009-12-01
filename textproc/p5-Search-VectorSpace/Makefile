# New ports collection makefile for:	p5-Search-VectorSpace
# Date created:		2004-10-26
# Whom:			clsung
#
# $FreeBSD$
#

PORTNAME=	Search-VectorSpace
PORTVERSION=	0.02
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A very basic vector-space search engine perl module

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PDL.pm:${PORTSDIR}/math/PDL \
		${SITE_PERL}/Lingua/Stem.pm:${PORTSDIR}/textproc/p5-Lingua-Stem
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Search::VectorSpace.3

.include <bsd.port.mk>
