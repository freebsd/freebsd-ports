# New ports collection makefile for:	p5-HTML-Element-Extended
# Date created:			20 September 2002
# Whom:				Garrett A. Wollman
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Extended
PORTVERSION=	1.17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extended interface to HTML::Tree's HTML::Element class

RUN_DEPENDS=	${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::ElementRaw.3 HTML::ElementGlob.3 \
		HTML::ElementSuper.3 HTML::ElementTable.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
