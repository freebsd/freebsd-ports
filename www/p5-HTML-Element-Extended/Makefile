# New ports collection makefile for:	p5-HTML-Element-Extended
# Date created:			20 September 2002
# Whom:				Garrett A. Wollman
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Extended
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	wollman@FreeBSD.org
COMMENT=	An extended interface to HTML::Tree's HTML::Element class

BUILD_DEPENDS=	${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::ElementRaw.3 HTML::ElementGlob.3 \
		HTML::ElementSuper.3 HTML::ElementTable.3

.include <bsd.port.mk>
