# New ports collection makefile for:	p5-HTML-Element-Extended
# Date created:			20 September 2002
# Whom:				Garrett A. Wollman
#
# $FreeBSD$
#

PORTNAME=	HTML-Element-Extended
PORTVERSION=	1.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An extended interface to HTML::Tree's HTML::Element class

RUN_DEPENDS=	${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::ElementRaw.3 HTML::ElementGlob.3 \
		HTML::ElementSuper.3 HTML::ElementTable.3

.include <bsd.port.mk>
