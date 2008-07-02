# New ports collection makefile for:	www/p5-HTML-Lint
# Date created:				27 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Lint
PORTVERSION=	2.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	HTML::Lint - check for HTML errors in a string or file

BUILD_DEPENDS=	p5-HTML-Tagset>0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Lint.3 \
	HTML::Lint::Error.3 \
	HTML::Lint::HTML4.3 \
	Test::HTML::Lint.3

.include <bsd.port.mk>
