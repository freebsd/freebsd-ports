# New ports collection makefile for:   p5-HTML-Chunks
# Date created:        27 November 2005
# Whom:                Alexander Koch <fbsd@meersau.de>
#
# $FreeBSD$
#

PORTNAME=	HTML-Chunks
PORTVERSION=	1.53
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd@meersau.de
COMMENT=	A simple nested template engine for HTML, XML and XHTML

RUN_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		HTML::Chunks.3 HTML::Chunks::Local.3 HTML::Chunks::Super.3 \
		HTML::ChunksLocal.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		needs Perl 5.8.6 or above (lang/perl5.8)
.endif

.include <bsd.port.post.mk>
