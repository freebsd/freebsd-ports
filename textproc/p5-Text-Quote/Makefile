# ex:ts=8
# Ports collection makefile for:	Text::Quote
# Date created:			Jul 29, 2006
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Text-Quote
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quotes strings as required for perl to eval them back correctly

RUN_DEPENDS=	p5-Carp-Assert>=0.13:${PORTSDIR}/devel/p5-Carp-Assert
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Text::Quote.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Compress-Zlib>=1.16:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.include <bsd.port.post.mk>
