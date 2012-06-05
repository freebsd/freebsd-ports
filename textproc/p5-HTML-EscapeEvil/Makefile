# New ports collection makefile for:	textproc/p5-HTML-EscapeEvil
# Date created:				13 February 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-EscapeEvil
PORTVERSION=	0.05
CATEGORIES=	textproc perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Escape evil HTML tags

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::EscapeEvil.3

.include <bsd.port.mk>
